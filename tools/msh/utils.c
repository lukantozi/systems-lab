#include "msh.h"

void *Malloc(size_t size) {
    char *ptr;
    if ((ptr = malloc(size)) == NULL) {
        perror("malloc");
        exit(ENOMEM);
    }
    return ptr;
}

void Realloc(void *ptr, size_t size) {
    char *new_ptr;
    if ((new_ptr = realloc(ptr, size)) == NULL) {
        free(ptr);
        perror("realloc");
        exit(ENOMEM);
    }
    ptr = new_ptr;
}
