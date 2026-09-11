# /// script
# requires-python = ">=3.10"
# dependencies = ["pypdf>=5"]
# ///

from __future__ import annotations

import argparse
import re
import sys
import time
from pathlib import Path
from urllib.parse import urlparse
from urllib.request import Request, urlopen

from pypdf import PdfReader, PdfWriter

LINK = re.compile(r"\[([^\]]+)\]\((https?://[^)\s]+)\)")
HEADING = re.compile(r"^(#{1,6})\s+(.+?)\s*$")


def plain(text: str) -> str:
    return LINK.sub(lambda m: m.group(1), text).strip()


def parse_index(path: Path):
    headings: list[tuple[int, str]] = []
    documents: list[tuple[str, str, list[tuple[int, str]]]] = []

    for raw in path.read_text(encoding="utf-8").splitlines():
        match = HEADING.match(raw)
        if match:
            level = len(match.group(1))
            title = plain(match.group(2))
            headings = [(n, name) for n, name in headings if n < level]
            headings.append((level, title))
            continue

        for title, url in LINK.findall(raw):
            if urlparse(url).path.lower().endswith(".pdf"):
                documents.append((title, url, headings.copy()))

    if not documents:
        raise ValueError(f"No PDF links found in {path}")
    return documents


def download(url: str, destination: Path, refresh: bool) -> Path:
    if destination.exists() and destination.stat().st_size > 0 and not refresh:
        return destination

    temporary = destination.with_suffix(destination.suffix + ".part")
    for attempt in range(1, 4):
        try:
            request = Request(url, headers={"User-Agent": "ostep-local-builder/1.0"})
            with urlopen(request, timeout=60) as response, temporary.open("wb") as out:
                while chunk := response.read(1024 * 1024):
                    out.write(chunk)
            if temporary.stat().st_size == 0:
                raise ValueError("empty response")
            temporary.replace(destination)
            return destination
        except Exception as exc:
            temporary.unlink(missing_ok=True)
            if attempt == 3:
                raise RuntimeError(f"Download failed: {url}") from exc
            print(f"Retrying ({attempt}/3): {url}", file=sys.stderr)
            time.sleep(attempt * 2)
    raise AssertionError("unreachable")


def add_headings(writer: PdfWriter, headings, active, page_number: int):
    common = 0
    while common < len(active) and common < len(headings):
        if active[common][0:2] != headings[common]:
            break
        common += 1
    active = active[:common]

    for level, title in headings[common:]:
        parent = active[-1][2] if active else None
        node = writer.add_outline_item(title, page_number, parent=parent, is_open=True)
        active.append((level, title, node))
    return active


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Download OSTEP PDFs linked by a Markdown index and merge them with bookmarks."
    )
    parser.add_argument("index", type=Path, help="Markdown index containing OSTEP PDF links")
    parser.add_argument("-o", "--output", type=Path, default=Path("ostep.pdf"))
    parser.add_argument("--refresh", action="store_true", help="Re-download cached PDFs")
    args = parser.parse_args()

    documents = parse_index(args.index)
    output = args.output.resolve()
    cache = output.parent / ".ostep-pdfs"
    cache.mkdir(parents=True, exist_ok=True)

    writer = PdfWriter()
    active = []
    total_pages = 0

    for number, (title, url, headings) in enumerate(documents, start=1):
        name = Path(urlparse(url).path).name
        local_pdf = download(url, cache / name, args.refresh)
        reader = PdfReader(local_pdf)
        start_page = len(writer.pages)
        active = add_headings(writer, headings, active, start_page)
        parent = active[-1][2] if active else None
        writer.add_outline_item(title, start_page, parent=parent, is_open=False)
        writer.append(reader, import_outline=False)
        total_pages += len(reader.pages)
        print(f"[{number:02d}/{len(documents)}] {title} ({len(reader.pages)} pages)")

    temporary = output.with_suffix(output.suffix + ".part")
    with temporary.open("wb") as out:
        writer.write(out)
    temporary.replace(output)
    print(f"Built {output} with {len(documents)} documents and {total_pages} pages.")


if __name__ == "__main__":
    main()
