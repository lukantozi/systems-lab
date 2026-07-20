#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct vector {
    int     *arr;
    size_t  size;
    size_t  inuse;  
};

vector *init_vector(size_t arrsize) {
    vector *vecptr = malloc(sizeof *vecptr);
    if (vecptr == NULL) return NULL;

    vecptr->arr = malloc(sizeof(int) * arrsize);
    if (vecptr->arr == NULL) {
        free(vecptr);
        return NULL;
    }

    memset(vecptr->arr, 0, sizeof(int) * arrsize);
    vecptr->size = arrsize;
    vecptr->inuse = 0;
    return vecptr;
}

int append_element(vector *vecptr, int x) {
    if (vecptr->inuse == vecptr->size) {
        size_t old_size = vecptr->size;
        size_t new_size = vecptr->size * 2 + 1;

        int *new_arr;
        new_arr = realloc(vecptr->arr, sizeof(int) * new_size);
        if (new_arr == NULL) {
            return 0;
        }
        vecptr->size = new_size;

        memset(new_arr + old_size, 0, sizeof(int) * (vecptr->size - old_size));
        vecptr->arr = new_arr;
    }

    *(vecptr->arr + vecptr->inuse++) = x;
    return 1;
}

int get_element(vector *vecptr, size_t ind) {
    if (ind >= vecptr->inuse) {
        fprintf(stderr, "Index error: %zu outside of array range\n", ind);
        exit(EXIT_FAILURE);
    }
    return vecptr->arr[ind];
}

size_t get_size_inmem(vector *vecptr) {
    return vecptr->size;
}

size_t get_size_inuse(vector *vecptr) {
    return vecptr->inuse;
}

void show_array(vector *vec) {
    if (vec->inuse > 0) {
        printf("[");
        size_t i;
        for (i = 0; i < vec->inuse; i++) {
            printf(i ? ", %d" : "%d", get_element(vec, i));
        }
        puts("]");
    }
}

void free_vector(vector *vecptr) {
    free(vecptr->arr);
    free(vecptr);
}
