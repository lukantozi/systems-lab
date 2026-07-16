CC     = gcc
CFLAGS = -Wall -Wextra

msh: msh.c builtins.c parser.c exec.c utils.c msh.h builtins.h parser.h exec.h utils.h
	$(CC) $(CFLAGS) msh.c parser.c exec.c builtins.c utils.c -o msh
