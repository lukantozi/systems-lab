#include "stack.h"
#include <stdio.h>
#include <assert.h>

int main(void) {
    puts("=======TEST STACK_1: START==========");
    int out_int;
    size_t out_size;
    stack *st = stack_init(5);
    assert(st != NULL);
    assert(stack_size(st, &out_size) == 1);
    assert(out_size == 0);
    assert(stack_show(st) == 1);
    assert(stack_push(st, 3) == 1);
    assert(stack_show(st) == 1);
    assert(stack_push(st, 4) == 1);
    assert(stack_show(st) == 1);

    assert(stack_pop(st, &out_int) == 1);
    assert(out_int == 4);
    assert(stack_show(st) == 1);

    assert(stack_pop(st, &out_int) == 1);
    assert(out_int == 3);
    assert(stack_show(st) == 1);

    assert(stack_pop(st, &out_int) == -1);

    assert(stack_push(st, 3) == 1);
    assert(stack_push(st, 6) == 1);
    assert(stack_push(st, 9) == 1);
    assert(stack_size(st, &out_size) == 1);
    assert(out_size == 3);
    assert(stack_show(st) == 1);
    assert(stack_peek(st, &out_int) == 1);
    assert(out_int == 9);

    while (out_size > 0) {
        assert(stack_pop(st, &out_int) == 1);
        assert(stack_size(st, &out_size) == 1);
    }
    assert(stack_show(st) == 1);

    int i;
    for (i = 0; i < 13; i++)
        assert(stack_push(st, i) == 1);
    assert(stack_show(st) == 1);

    while (i-1 >= 0) {
        assert(stack_peek(st, &out_int) == 1);
        assert(out_int == (i - 1));
        assert(stack_pop(st, &out_int) == 1);
        assert(out_int == (i - 1));
        i--;
    }
    assert(stack_show(st) == 1);

    out_int = 13456;
    assert(stack_pop(st, &out_int) == -1);
    assert(out_int == 13456);
    assert(stack_peek(st, &out_int) == -1);
    assert(out_int == 13456);

    assert(stack_pop(st, NULL) == -1);
    assert(stack_peek(st, NULL) == -1);

    assert(stack_free(NULL) == -1);
    assert(stack_free(st) == 1);
    puts("=======TEST STACK_1: SUCCESS========");
}
