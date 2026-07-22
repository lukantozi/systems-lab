#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct vector {
    int     *arr;
    size_t  capacity;
    size_t  size;  
};

vector *vector_init(size_t arrsize) {
    vector *vecptr = malloc(sizeof *vecptr);
    if (vecptr == NULL) return NULL;

    vecptr->arr = malloc(sizeof(int) * arrsize);
    if (vecptr->arr == NULL) {
        free(vecptr);
        return NULL;
    }

    memset(vecptr->arr, 0, sizeof(int) * arrsize);
    vecptr->capacity = arrsize;
    vecptr->size = 0;
    return vecptr;
}

int vector_append(vector *vecptr, int x) {
    if (vecptr->size == vecptr->capacity) {
        size_t old_capacity = vecptr->capacity;
        size_t new_capacity = vecptr->capacity * 2 + 1;

        int *new_arr;
        new_arr = realloc(vecptr->arr, sizeof(int) * new_capacity);
        if (new_arr == NULL) {
            return 0;
        }
        vecptr->capacity = new_capacity;

        memset(new_arr + old_capacity, 0, sizeof(int) * (vecptr->capacity - old_capacity));
        vecptr->arr = new_arr;
    }

    *(vecptr->arr + vecptr->size++) = x;
    return 1;
}

int vector_get(vector *vecptr, size_t ind) {
    if (ind >= vecptr->size) {
        fprintf(stderr, "Index error: %zu outside of array range\n", ind);
        exit(EXIT_FAILURE);
    }
    return vecptr->arr[ind];
}

size_t vector_capacity(vector *vecptr) {
    return vecptr->capacity;
}

size_t vector_size(vector *vecptr) {
    return vecptr->size;
}

void vector_show(vector *vec) {
    if (vec->size > 0) {
        printf("[");
        size_t i;
        for (i = 0; i < vec->size; i++) {
            printf(i ? ", %d" : "%d", vector_get(vec, i));
        }
        puts("]");
    }
}

void vector_free(vector *vecptr) {
    free(vecptr->arr);
    free(vecptr);
}
