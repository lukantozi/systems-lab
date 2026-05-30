# mls

Minimal clone of `ls -l` in C.

- Lists entries in the current directory by default, or in one directory passed as an argument
- Uses `opendir`, `readdir`, and `stat` to gather metadata for each entry
- Prints file mode, link count, uid, gid, size, modification time, and filename
- Usage: `mls` or `mls DIR`

Next:
- Format `st_mode` into `-rwxr-xr-x` style output
- Resolve uid/gid to user and group names
- Match `ls -l` formatting more closely
- Add flags later
