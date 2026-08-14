#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define VECTOR_NULL_ERROR(prog, arg, ret) \
    do { \
        fprintf(stderr, "[ERROR] vector_%s: %s is NULL\n", prog, arg); \
        return ret; \
    } while (0)

#define VECTOR_BOUND_ERROR(prog, ind, bound, ret) \
    do { \
        fprintf(stderr, "[ERROR] vector_%s: %zu exceeds the upper bound %zu\n", \
                prog, ind, bound); \
        return ret; \
    } while (0)

#define VECTOR_EMPTY_ERROR(prog) \
    do { \
        fprintf(stderr, "[ERROR] vector_%s: %s from empty vector\n", prog, prog); \
        return -1; \
    } while (0)

struct vector {
    int     *arr;
    size_t  capacity;
    size_t  size;  
};

vector *vector_init(size_t arrsize) {
    if (arrsize == 0) {
        fprintf(stderr, "[ERROR] vector_init: arrsize is 0\n");
        return NULL;
    }

    vector *vecptr = malloc(sizeof *vecptr);
    if (vecptr == NULL)
        VECTOR_NULL_ERROR("init", "vecptr", NULL);

    vecptr->arr = malloc(sizeof(int) * arrsize);
    if (vecptr->arr == NULL) {
        free(vecptr);
        VECTOR_NULL_ERROR("init", "vecptr->arr", NULL);
    }

    memset(vecptr->arr, 0, sizeof(int) * arrsize);
    vecptr->capacity = arrsize;
    vecptr->size = 0;
    return vecptr;
}

static int *vector_grow(vector *vecptr) {
    size_t old_capacity = vecptr->capacity;
    size_t new_capacity = vecptr->capacity * 2;

    int *new_arr;
    new_arr = realloc(vecptr->arr, sizeof(int) * new_capacity);
    if (new_arr == NULL)
        VECTOR_NULL_ERROR("grow", "new_arr", NULL);

    vecptr->capacity = new_capacity;
    memset(new_arr + old_capacity, 0, sizeof(int) * (vecptr->capacity - old_capacity));
    return new_arr;
}

static int *vector_shrink(vector *vecptr) {
    size_t half_capacity = vecptr->capacity / 2;
    size_t new_capacity = half_capacity > 0 ? half_capacity : 1;
    int *new_arr;

    new_arr = realloc(vecptr->arr, sizeof(int) * new_capacity);
    if (new_arr == NULL)
        VECTOR_NULL_ERROR("shrink", "new_arr", NULL);

    vecptr->capacity = new_capacity;
    return new_arr;
}

int vector_append(vector *vecptr, int x) {
    if (vecptr == NULL)
        VECTOR_NULL_ERROR("append", "vecptr", -1);

    if (vecptr->size == vecptr->capacity) {
        int *new_arr = vector_grow(vecptr);
        if (new_arr == NULL)
            VECTOR_NULL_ERROR("append", "new_arr", -1);
        vecptr->arr = new_arr;
    }

    *(vecptr->arr + vecptr->size++) = x;
    return 1;
}

int vector_insert(vector *vecptr, size_t ind, int x) {
    if (vecptr == NULL)
        VECTOR_NULL_ERROR("insert", "vecptr", -1);

    if (ind > vecptr->size)
        VECTOR_BOUND_ERROR("insert", ind, vecptr->size, -1);

    if (vecptr->size == vecptr->capacity) {
        int *new_arr = vector_grow(vecptr);
        if (new_arr == NULL)
            VECTOR_NULL_ERROR("insert", "new_arr", -1);
        vecptr->arr = new_arr;
    }

    for (size_t i = vecptr->size; i > ind; i--)
        *(vecptr->arr + i) = *(vecptr->arr + i - 1);

    *(vecptr->arr + ind) = x;
    vecptr->size++;
    return 1;
}

int vector_remove(vector *vecptr, size_t ind, int *rem_val) {
    if (vecptr == NULL)
        VECTOR_NULL_ERROR("remove", "vecptr", -1);

    if (rem_val == NULL)
        VECTOR_NULL_ERROR("remove", "rem_val", -1);

    if (vecptr->size == 0)
        VECTOR_EMPTY_ERROR("remove");

    if (ind >= vecptr->size)
        VECTOR_BOUND_ERROR("remove", ind, vecptr->size, -1);

    *rem_val = *(vecptr->arr + ind);
    for (size_t i = ind; i < vecptr->size-1; i++)
        *(vecptr->arr + i) = *(vecptr->arr + i + 1);

    vecptr->size--;
    if (vecptr->size < vecptr->capacity / 4) {
        int *new_arr = vector_shrink(vecptr);
        if (new_arr != NULL)
            vecptr->arr = new_arr;
    }

    return 1;
}

int vector_pop(vector *vecptr, int *popped) {
    if (vecptr == NULL)
        VECTOR_NULL_ERROR("pop", "vecptr", -1);

    if (popped == NULL)
        VECTOR_NULL_ERROR("pop", "popped", -1);

    if (vecptr->size == 0) 
        VECTOR_EMPTY_ERROR("pop");

    return vector_remove(vecptr, vecptr->size-1, popped);
}

int vector_get(vector *vecptr, size_t ind, int *val) {
    if (vecptr == NULL)
        VECTOR_NULL_ERROR("get", "vecptr", -1);

    if (val == NULL)
        VECTOR_NULL_ERROR("get", "val", -1);

    if (ind >= vecptr->size)
        VECTOR_BOUND_ERROR("get", ind, vecptr->size, -1);


    *val = vecptr->arr[ind];
    return 1;
}

int vector_swap(vector *vecptr, size_t ind1, size_t ind2) {
    if (vecptr == NULL)
        VECTOR_NULL_ERROR("swap", "vecptr", -1);

    if (ind1 >= vecptr->size)
        VECTOR_BOUND_ERROR("swap", ind1, vecptr->size, -1);

    if (ind2 >= vecptr->size)
        VECTOR_BOUND_ERROR("swap", ind2, vecptr->size, -1);

    int tmp = vecptr->arr[ind1];
    vecptr->arr[ind1] = vecptr->arr[ind2];
    vecptr->arr[ind2] = tmp;

    return 1;
}

int vector_capacity(vector *vecptr, size_t *cap) {
    if (vecptr == NULL)
        VECTOR_NULL_ERROR("capacity", "vecptr", -1);

    if (cap == NULL)
        VECTOR_NULL_ERROR("capacity", "cap", -1);

    *cap = vecptr->capacity;
    return 1;
}

int vector_size(vector *vecptr, size_t *siz) {
    if (vecptr == NULL)
        VECTOR_NULL_ERROR("size", "vecptr", -1);

    if (siz == NULL)
        VECTOR_NULL_ERROR("size", "siz", -1);

    *siz = vecptr->size;
    return 1;
}

int vector_show(vector *vec) {
    if (vec == NULL)
        VECTOR_NULL_ERROR("show", "vec", -1);

    if (vec->size == 0) {
        puts("[]");
    } else if (vec->size > 0) {
        printf("[");
        size_t i;
        int val;
        for (i = 0; i < vec->size; i++) {
            if (vector_get(vec, i, &val) == 1)
                printf(i ? ", %d" : "%d", val);
        }
        puts("]");
    }
    return 1;
}

int vector_free(vector *vecptr) {
    if (vecptr == NULL)
        VECTOR_NULL_ERROR("free", "vecptr", -1);

    free(vecptr->arr);
    free(vecptr);
    return 1;
}
