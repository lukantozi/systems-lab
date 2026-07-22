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

static int *vector_grow(vector *vecptr) {
    size_t old_capacity = vecptr->capacity;
    size_t new_capacity = vecptr->capacity * 2 + 1;

    int *new_arr;
    new_arr = realloc(vecptr->arr, sizeof(int) * new_capacity);
    if (new_arr == NULL) {
        return 0;
    }
    vecptr->capacity = new_capacity;
    memset(new_arr + old_capacity, 0, sizeof(int) * (vecptr->capacity - old_capacity));

    return new_arr;
}

static int *vector_shrink(vector *vecptr) {
    size_t new_capacity = vecptr->capacity / 2 + 1;

    int *new_arr;
    new_arr = realloc(vecptr->arr, sizeof(int) * new_capacity);
    if (new_arr == NULL) {
        return 0;
    }
    vecptr->capacity = new_capacity;

    return new_arr;
}

static void vector_bound_error(size_t ind) {
    fprintf(stderr, "Index error: %zu outside of vector range\n", ind);
    exit(EXIT_FAILURE);
}

static void vector_empty_error(void) {
    fprintf(stderr, "Can't remove elements from empty vector: []\n");
    exit(EXIT_FAILURE);
}

int vector_append(vector *vecptr, int x) {
    if (vecptr->size == vecptr->capacity) {
        int *new_arr = vector_grow(vecptr);
        if (new_arr == NULL) {
            return 0;
        }
        vecptr->arr = new_arr;
    }

    *(vecptr->arr + vecptr->size++) = x;
    return 1;
}

int vector_insert(vector *vecptr, size_t ind, int x) {
    if (ind > vecptr->size) {
        vector_bound_error(ind);
    }
    
    if (vecptr->size == vecptr->capacity) {
        int *new_arr = vector_grow(vecptr);
        if (new_arr == NULL) {
            return 0;
        }
        vecptr->arr = new_arr;
    }

    for (size_t i = vecptr->size; i > ind; i--) {
        *(vecptr->arr + i) = *(vecptr->arr + i - 1);
    }

    *(vecptr->arr + ind) = x;
    vecptr->size++;
    return 1;
}

int vector_remove(vector *vecptr, size_t ind, int *rem_val) {
    if (vecptr->size == 0) {
        vector_empty_error();
    }
    if (ind >= vecptr->size) {
        vector_bound_error(ind);
    }

    *rem_val = *(vecptr->arr + ind);
    for (size_t i = ind; i < vecptr->size-1; i++) {
        *(vecptr->arr + i) = *(vecptr->arr + i + 1);
    }
    vecptr->size--;

    if (vecptr->size * 2 < vecptr->capacity) {
        int *new_arr = vector_shrink(vecptr);
        if (new_arr != NULL) {
            vecptr->arr = new_arr;
        }
    }

    return 1;
}

int vector_pop(vector *vecptr, int *popped) {
    if (vecptr->size == 0) vector_empty_error();
    return vector_remove(vecptr, vecptr->size-1, popped);
}

int vector_get(vector *vecptr, size_t ind) {
    if (ind >= vecptr->size) {
        vector_bound_error(ind);
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
    if (vec->size == 0) {
        puts("[]");
    } else if (vec->size > 0) {
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
