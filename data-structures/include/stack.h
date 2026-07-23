#ifndef STACK_H
#define STACK_H
#include "vector.h"

typedef struct vector stack;

stack *stack_init(size_t);
int stack_push(stack *, int);
int stack_pop(stack *, int *);
int stack_peek(stack *);
int stack_is_empty(stack *);
void stack_free(stack *);

#endif
