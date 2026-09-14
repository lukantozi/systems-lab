#include <inttypes.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*
 * after executing this function we can observe
 * that child and parent each have their own x
 * and modifying it in child does not affect its
 * value in parent.
 */
void task_1(void) {
    int x = 100;

    int status;
    int pid = fork();
    switch (pid) {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            printf("from child(%d):  initial  x is %d\n", getpid(), x);
            x = 10;
            printf("from child(%d):  modified x is %d\n", getpid(), x);
            fflush(stdout);
            _exit(0);
        default:
            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid");
                exit(1);
            }
            printf("from parent(%d): initial  x is %d\n", getpid(), x);
            x = 1;
            printf("from parent(%d): modified x is %d\n", getpid(), x);
    }
}

/* 
 * both child and parent can write to the same file, since
 * after forking child recieves the fd of the open file.
 */
void task_2(void) {
    if (close(STDOUT_FILENO) == -1) {
        perror("close");
        exit(1);
    }
    if (open("temp-file", O_TRUNC | O_RDWR | O_CREAT, S_IRWXU) == -1) {
        perror("open");
        exit(1);
    }

    int status;
    int pid = fork();
    switch (pid) {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            puts("writing from child");
            fflush(stdout);
            _exit(0);
        default:
            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid");
                exit(1);
            }
            puts("writing from parent");
    }
}

/* 
 * making sure child prints "hello" before parent's
 * "goodbye" without wait()
 */
void task_3(void) {
    int pid = fork();
    switch (pid) {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            puts("hello");
            fflush(stdout);
            _exit(0);
        default:
            for (unsigned int i = 0; i < 0x80000000; i++);
            puts("goodbye");
    }
}

void task_4(void) {
    int status;
    int pid = fork();
    switch (pid) {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            char *argv[3];
            argv[0] = "/bin/ls";
            argv[1] = "-l";
            argv[2] = NULL;
            execvp(argv[0], argv);
            perror("execvp");
            _exit(1);

            // execl("/bin/ls", NULL);
        default:
            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid");
                exit(1);
            }
    }
}

void task_5_6(void) {
    /*
     * used wait/waitpid in some of the above functions
     * waitpid is useful when we want to specify which child
     * we are waiting to die for
     */
}

/* 
 * child is unable to print string anywhere after
 * closing the STDOUT_FILENO. printf copies the string
 * into the buffer, but it stays there and the error is
 * not returned as a status. we can flush the buffer and
 * then we will see the error status code
 */
void task_7(void) {
    int wstatus;
    int print_status = 123;
    int pid = fork();
    switch (pid) {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            if (close(STDOUT_FILENO) == -1) {
                perror("close");
                _exit(1);
            }
            print_status = printf("echoing into abyss");
            fprintf(stderr, "print_status: %d\n", print_status);
            print_status = fflush(stdout); /* flush the buffer */
            fprintf(stderr, "print_status: %d\n", print_status);
            _exit(0);
        default:
            if (waitpid(pid, &wstatus, 0) == -1) {
                perror("waitpid");
                _exit(1);
            }
    }
}

void close_pipes(int pipefd[]) {
    if (close(pipefd[0]) == -1) {
        perror("close: pipefd[0]");
        _exit(1);
    }
    if (close(pipefd[1]) == -1) {
        perror("close: pipefd[1]");
        _exit(1);
    }
}

void task_8(void) {
    int pipefd[2];
    int wstatus;
    int pid;
    char buf;

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid = fork();
    switch (pid) {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
                perror("dup2: pipefd[1]");
                _exit(1);
            }
            close_pipes(pipefd);
            puts("hello from first child");
            fflush(stdout);
            _exit(0);
        default:
            if (waitpid(pid, &wstatus, 0) == -1) {
                perror("waitpid");
                exit(1);
            }
    }

    pid = fork();
    switch (pid) {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            puts("entering second child");
            if (dup2(pipefd[0], STDIN_FILENO) == -1) {
                perror("dup2: pipefd[0]");
                _exit(1);
            }
            close_pipes(pipefd);
            while (read(STDIN_FILENO, &buf, 1) > 0) {
                if (write(STDOUT_FILENO, &buf, 1) != 1) {
                    perror("write");
                    _exit(1);
                }
            }
            _exit(0);
        default:
            close_pipes(pipefd);
            if (waitpid(pid, &wstatus, 0) == -1) {
                perror("waitpid");
                exit(1);
            }
    }
}

int main(void) {
#if 0
    task_1();
    task_2();
    task_3();
    task_4();
    task_7();
#endif
    task_8();
}
