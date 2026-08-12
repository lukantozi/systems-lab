#include "stack.h"
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

#define STACK_NULL_ERROR(prog, arg, ret) \
    do { \
        fprintf(stderr, "[ERROR] stack_%s: %s is NULL\n", prog, arg); \
        return ret; \
    } while (0)

#define STACK_EMPTY_ERROR(prog) \
    do { \
        fprintf(stderr, "[ERROR] stack_%s: %s from empty stack\n", prog, prog); \
        return -1; \
    } while (0)

struct stack {
    vector *storage;
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

    stp->storage = vpt;
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

    return vector_append(stp->storage, val);
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

    free(stp);
    return 1;
}
