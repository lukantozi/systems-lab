# mcut

Minimal clone of `cut(1)` in C.

- Reads from stdin by default, or from files passed as arguments
- Extracts the first field from each line, delimited by a space
- Prints extracted fields to stdout, one per line
- Uses a dynamically grown buffer with `malloc`/`realloc`

Usage:
- `mcut`
- `mcut input.txt`
- `mcut file1.txt file2.txt`

Current limitations:
- Only supports a single hardcoded delimiter (space, `0x20`)
- Only extracts the first field per line
- Dynamic buffer grows in 50-byte increments, not optimized
