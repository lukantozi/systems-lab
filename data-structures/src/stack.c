#include "stack.h"
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

#define STACK_NULL_ERROR(prog, arg, ret) \
    do { \
        fprintf(stderr, "[ERROR] stack_%s: %s is NULL\n", \
                prog, arg); \
        return ret; \
    } while (0)

#define STACK_EMPTY_ERROR(prog) \
    do { \
        fprintf(stderr, "[ERROR] stack_%s: %s from empty stack\n", \
                prog, prog); \
        return -1; \
    } while (0)

struct stack {
    vector *storage;
    vector *mins;
};

stack *stack_init(size_t size) {
    stack *stp = malloc(sizeof(*stp));
    if (stp == NULL)
        STACK_NULL_ERROR("init", "stp", NULL);

    vector *vpt = vector_init(size);
    if (vpt == NULL) {
        free(stp);
        return NULL;
    }

    vector *min_vec = vector_init(size);
    if (min_vec == NULL) {
        vector_free(vpt);
        free(stp);
        return NULL;
    }

    stp->storage = vpt;
    stp->mins = min_vec;
    return stp;
}

int stack_size(stack *stp, size_t *siz) {
    if (stp == NULL)
        STACK_NULL_ERROR("size", "stp", -1);

    if (siz == NULL)
        STACK_NULL_ERROR("size", "siz", -1);

    if (vector_size(stp->storage, siz) == -1)
        return -1;

    return 1;
}

int stack_is_empty(stack *stp) {
    if (stp == NULL)
        STACK_NULL_ERROR("is_empty", "stp", -1);

    size_t siz;
    if (stack_size(stp, &siz) == -1)
        return -1;

    return siz == 0;
}

int stack_is_full(stack *stp) {
    if (stp == NULL)
        STACK_NULL_ERROR("is_full", "stp", -1);

    size_t siz, cap;
    if (stack_size(stp, &siz) == -1)
        return -1;

    if (vector_capacity(stp->storage, &cap) == -1)
        return -1;

    return siz == cap;
}

int stack_push(stack *stp, int val) {
    if (stp == NULL)
        STACK_NULL_ERROR("push", "stp", -1);

    size_t min_size;
    if (vector_size(stp->mins, &min_size) == -1)
        return -1;

    int min;
    if (min_size == 0) {
        min = val;
    } else {
        if (vector_get(stp->mins, min_size - 1, &min) == -1)
            return -1;
    }

    if (val >= min) {
        if (vector_append(stp->mins, min) == -1)
            return -1;
    } else {
        if (vector_append(stp->mins, val) == -1)
            return -1;
    }

    int append = vector_append(stp->storage, val);
    if (append == -1) {
        if (vector_pop(stp->mins, &min) == -1)
            return -1;
    }

    return append;
}

int stack_pop(stack *stp, int *popped) {
    if (stp == NULL)
        STACK_NULL_ERROR("pop", "stp", -1);

    if (popped == NULL)
        STACK_NULL_ERROR("pop", "popped", -1);

    int empty = stack_is_empty(stp); 
    if (empty == -1)
        return -1;

    if (empty == 1)
        STACK_EMPTY_ERROR("pop");

    if (vector_pop(stp->mins, &empty) == -1)
        return -1;

    return vector_pop(stp->storage, popped);
}

int stack_peek(stack *stp, int *pkd) {
    if (stp == NULL)
        STACK_NULL_ERROR("peek", "stp", -1);

    if (pkd == NULL)
        STACK_NULL_ERROR("peek", "pkd", -1);

    size_t siz;
    if (stack_size(stp, &siz) == -1)
        return -1;

    if (siz == 0)
        STACK_EMPTY_ERROR("peek");

    return vector_get(stp->storage, siz - 1, pkd);
}

int stack_find_min(stack *stp, int *min) {
    if (stp == NULL)
        STACK_NULL_ERROR("find_min", "stp", -1);

    if (min == NULL)
        STACK_NULL_ERROR("find_min", "min", -1);

    size_t siz;
    if (vector_size(stp->mins, &siz) == -1)
        return -1;

    if (siz == 0)
        STACK_EMPTY_ERROR("find_min");

    if (vector_get(stp->mins, siz-1, min) == -1)
        return -1;

    return 1;
}

int stack_show(stack *stp) {
    if (stp == NULL)
        STACK_NULL_ERROR("show", "stp", -1);

    return vector_show(stp->storage);
}

int stack_free(stack *stp) {
    if (stp == NULL)
        STACK_NULL_ERROR("free", "stp", -1);

    if (vector_free(stp->storage) == -1)
        return -1;

    if (vector_free(stp->mins) == -1)
        return -1;

    free(stp);
    return 1;
}
