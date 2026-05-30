# mtee

Minimal clone of `tee(1)` in C.

- Reads from stdin and writes to stdout
- Simultaneously writes to one or more files passed as arguments
- Uses `fgets` with a 4KB buffer for streaming input
- Calls `fflush` after each write to ensure real-time output to files
- Usage: `command | mtee file1 file2 ...`

Implementation notes:
- Opens files in append mode (`"a"`)
- Skips files that fail to open, continues with valid ones
- Uses dynamic file handle array sized to `argc-1`

Next:
- Add `-a` flag to explicitly control append vs overwrite behavior
- Handle signals (e.g. `SIGINT`) to flush and close files cleanly before exit
