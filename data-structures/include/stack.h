#include <stddef.h>

#ifndef STACK_H
#define STACK_H

typedef struct stack stack;

stack *stack_init(size_t);
int stack_size(stack *, size_t *);
int stack_is_empty(stack *);
int stack_is_full(stack *);
int stack_push(stack *, int);
int stack_pop(stack *, int *);
int stack_peek(stack *, int *);
int stack_find_min(stack *, int *);
int stack_show(stack *);
int stack_free(stack *);

#endif
