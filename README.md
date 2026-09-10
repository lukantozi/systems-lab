# systems-lab

Systems programming in C, built from first principles.

This repository is my long-term lab for learning C, Unix process and file
interfaces, computer systems, algorithms, and data structures through small
programs, exercises, and progressively larger projects.

Study tracks:

- CS:APP
- Beej's Guide to C
- Skiena's Algorithm Design Manual

***

## Unix Tools (C)

Unix-style tools built from scratch to practice process creation, pipes, file
descriptors, environment handling, filesystem traversal, and text/file
interfaces.

The main project is [msh](tools/msh/), a small interactive shell with commands,
builtins, and pipelines. See [tools README](tools/README.md) for the full tool catalogue.

***

## Data Structures (C)

A tested C data-structures library in [`data-structures/`](data-structures/)
with public headers, implementations, tests, and a Makefile.

Implemented structures include a vector, stack, circular queue, singly and
doubly linked lists, hash map, binary heap, and binary search tree.

***

## LeetCode

LeetCode solutions in C and Python, organized by problem number in
[`leetcode/`](leetcode/).

***

## Study

Book exercises, experiments, and typed examples.

| Material | Path | Focus |
|----------|------|-------|
| CS:APP 3e | [`study/csapp/`](study/csapp/) | Data representation, bit manipulation, systems programming |
| Beej's Guide to C | [`study/bgc/`](study/bgc/) | C language experiments and examples |
| Algorithm Design Manual | [`study/adm/`](study/adm/) | Algorithm analysis and implementations |

***

## Katas (Python)

Structured systems-design exercises with leveled test suites.

| Kata | Description | Tests |
|------|-------------|-------|
| [minikv](katas/minikv/) | In-memory key-value store | 5 levels |
| [mini-file-storage](katas/mini-file-storage/) | File storage system | 4 levels |
