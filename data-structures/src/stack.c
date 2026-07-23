#include "vector.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

stack *stack_init(size_t size) {
    return vector_init(size);
}

int stack_push(stack *stptr, int x) {
    return vector_append(stptr, x);
}

int stack_pop(stack *stptr, int *popped) {
    return vector_pop(stptr, popped);
}

int stack_peek(stack *stptr) {
    if (vector_size(stptr) == 0) {
        fprintf(stderr, "cannot peek an empty vector\n");
        exit(EXIT_FAILURE);
    }
    return vector_get(stptr, vector_size(stptr) - 1);
}

int stack_is_empty(stack *stptr) {
    return vector_size(stptr) == 0;
}

int stack_is_full(stack *stptr) {
    return vector_size(stptr) == vector_capacity(stptr);
}

void stack_free(stack *stptr) {
    vector_free(stptr);
}
