#include "stack.h"
#include "stdio.h"
#include "assert.h"

int main(void) {
    stack *st = stack_init(5);
    assert(st != NULL);

    assert(1 == stack_is_empty(st));

    stack_push(st, 5);
    stack_push(st, 4);
    stack_push(st, 3);
    stack_push(st, 2);
    stack_push(st, 1);

    int popped;
    assert(1 == stack_peek(st));
    stack_pop(st, &popped);
    assert(1 == popped);
    printf("popped: %d\n", popped);

    stack_pop(st, &popped);
    printf("popped: %d\n", popped);
    assert(2 == popped);

    stack_pop(st, &popped);
    printf("popped: %d\n", popped);
    assert(3 == popped);

    stack_pop(st, &popped);
    printf("popped: %d\n", popped);

    assert(0 == stack_is_empty(st));

    stack_pop(st, &popped);
    printf("popped: %d\n", popped);

    assert(1 == stack_is_empty(st));

    stack_free(st);
}
