# muniq

Minimal clone of `uniq(1)` in C.

- Reads from stdin by default, or from a file passed as an argument
- Removes consecutive duplicate lines
- Can write output to stdout or to a destination file
- Uses fixed-size buffers with `fgets`, `strcmp`, and `strcpy`

Usage:
- `muniq`
- `muniq input.txt`
- `muniq input.txt output.txt`

Current limitations:
- Only removes consecutive duplicate lines
- Uses fixed-size buffers, so very long lines are not handled specially
