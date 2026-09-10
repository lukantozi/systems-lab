## Tools (C)

Unix-style tools built from scratch. Individual tool READMEs document
implemented behavior and deliberate limitations where available.

| Tool | Description | Status |
|------|-------------|--------|
| [msh](tools/msh/) | Interactive shell v1: commands, builtins, and pipelines | working |
| [mpipe](tools/mpipe/) | Connect commands with `pipe(2)` and `dup2(2)` | working |
| [mxargs-lite](tools/mxargs-lite/) | Build and execute command arguments from stdin | working |
| [menv](tools/menv/) | Run a command with modified environment variables | working |
| [mtr](tools/mtr/) | Run a command and report timing and exit status | working |
| [mfind](tools/mfind/) | Recursively find matching paths | working |
| [mhex](tools/mhex/) | Hex dump with offsets, bytes, and ASCII view | working |
| [mls](tools/mls/) | `ls -l`-style file metadata listing | working |
| [mmv](tools/mmv/) | Move files using `rename(2)` | working |
| [mcp](tools/mcp/) | `cp(1)` clone — copy files and directories | working |
| [mtee](tools/mtee/) | `tee(1)` clone — copy stdin to stdout and files | working |
| [mwc](tools/mwc/) | `wc(1)` clone — count lines, words, and characters | working |
| [mgrep](tools/mgrep/) | `grep(1)`-style line matcher | working |
| [msed-lite](tools/msed-lite/) | Replace occurrences of one string with another | working |
| [mcut](tools/mcut/) | Extract a delimiter-separated column from each line | working |
| [muniq](tools/muniq/) | `uniq(1)`-style consecutive duplicate-line filter | working |
| [mrev](tools/mrev/) | Reverse lines or file bytes | working |
| [mhead](tools/mhead/) | `head(1)` clone — print first N lines | working |
| [mtail](tools/mtail/) | `tail(1)` clone — print last N lines | working |
| [mcat](tools/mcat/) | `cat(1)` clone — concatenate and print files | working |
