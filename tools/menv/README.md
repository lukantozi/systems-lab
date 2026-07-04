## menv

A minimal clone of `env(1)` in C.

### Features
- `KEY=VALUE` assignments before the command, injected via `setenv`
- `-u NAME` to unset a variable
- `-C DIR` to chdir before exec
- Falls back to printing the environment when no command is given

### Known limitations
- Uses `execve()`, not `execvp()` -- the command must be given as a full or relative path; there is no `PATH` search yet. This is a deliberate scope decision.
