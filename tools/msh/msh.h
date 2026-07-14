#ifndef MSH_H
#define MSH_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>
#include <unistd.h>
#include <wait.h>
#include <errno.h>

#define DELIM   " \n\t\r\a"
#define TOKENSIZE  64
#define BUFSIZE 1024

void *Malloc(size_t);
void Realloc(void *, size_t);

#endif
