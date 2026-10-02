# OSTEP project: Intro to kernel hacking

## Sources
- [OSTEP assignment](https://github.com/remzi-arpacidusseau/ostep-projects/tree/master/initial-xv6)
- [xv6 documentation](https://pdos.csail.mit.edu/6.828/2017/xv6.html)

## Description
Adds the `getreadcount()` system call to xv6. It returns
the total number of `read()` calls made by all user
processes since the kernel booted.

The patch also includes compiler compatibility changes
needed for my environment.
