# msh

`msh` is a small interactive Unix-like shell written in C as a part
of my systems-programming practice.

It is not intended to replace a real shell. The goal is to understand
how a shell reads commands, creates processes, executes programs, and
connects them with pipes.

## Build

```sh
make
```

## Run

```sh
./msh
```

Press `Ctrl+D` or run `exit` to leave the shell.

## Implemented

- Interactive prompt showing the current working directory
- Whitespace-delimited command tokenization
- External command execution using `fork()` and `execvp()`
- Builtins: `cd`, `env`, and `exit`
- Pipelines with one or more `|` operators
- Dynamic input and token-array growth via `realloc()`

## Examples

The `❯` prompt below is my host shell; `>` is the `msh` prompt.

```sh
❯ ./msh

/home/styx/systems-lab/tools/msh
> pwd
/home/styx/systems-lab/tools/msh

/home/styx/systems-lab/tools/msh
> echo hello from msh
hello from msh

/home/styx/systems-lab/tools/msh
> printf 'alpha\nbeta\ngamma\n' | wc -l
3

/home/styx/systems-lab/tools/msh
> seq 1 10 | tail -3
8
9
10

/home/styx/systems-lab/tools/msh
> cd /tmp

/tmp
> pwd
/tmp
> exit

systems-lab/tools/msh on  main [?] via  v16.1.1-gcc
❯
```

## Pipeline model

For an N-command pipeline, `msh` creates N-1 pipes and forks all N
children before waiting. Each child uses `dup2()` to connect its
standard input/output to the appropriate pipe end, closes inherited
pipe descriptors, then calls `execvp()`.

The parent closes its copies of every pipe descriptor and reaps all
children with `waitpid()`. Closing unused write ends matters because
a reader receives EOF only after every copy of the pipe's write end
is closed.

## Current limitations

- No input/output redirection (`<`, `>`, `>>`)
- No quoting or escaping; spaces always split arguments
- No expansion of variables such as `$?` or `$HOME`
- No glob expansion (`*.c`)
- No background jobs, job control, or signal-safe prompt handling
- Builtins inside a pipeline do not have full real-shell semantics
