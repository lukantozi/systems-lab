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

    int min;
    assert(stack_find_min(st, &min) == 1);
    assert(stack_show(st) == 1);
    assert(min == 3);
    printf("min: %d\n", min);

    while (out_size > 0) {
        assert(stack_pop(st, &out_int) == 1);
        assert(stack_size(st, &out_size) == 1);
    }
    assert(stack_show(st) == 1);

    int i;
    for (i = 0; i < 13; i++)
        assert(stack_push(st, i) == 1);
    assert(stack_show(st) == 1);

    assert(stack_find_min(st, &min) == 1);
    assert(stack_show(st) == 1);
    assert(min == 0);
    printf("min: %d\n", min);

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
    putchar('\n');

    puts("=======TEST STACK_2: START==========");
    stack *st1 = stack_init(5);
    assert(st1 != NULL);
    assert(stack_size(st1, &out_size) == 1);
    assert(out_size == 0);

    assert(stack_push(st1, 4) == 1);
    assert(stack_find_min(st1, &min) == 1);
    assert(stack_show(st1) == 1);
    assert(min == 4);
    printf("min: %d\n", min);

    assert(stack_push(st1, 5) == 1);
    assert(stack_find_min(st1, &min) == 1);
    assert(stack_show(st1) == 1);
    assert(min == 4);
    printf("min: %d\n", min);

    assert(stack_push(st1, 3) == 1);
    assert(stack_find_min(st1, &min) == 1);
    assert(stack_show(st1) == 1);
    assert(min == 3);
    printf("min: %d\n", min);

    assert(stack_pop(st1, &out_int) == 1);
    assert(out_int == 3);

    assert(stack_find_min(st1, &min) == 1);
    assert(stack_show(st1) == 1);
    assert(min == 4);
    printf("min: %d\n", min);

    assert(stack_pop(st1, &out_int) == 1);
    assert(stack_find_min(st1, &min) == 1);
    assert(stack_show(st1) == 1);
    assert(min == 4);
    printf("min: %d\n", min);
    assert(stack_show(st1) == 1);
    assert(stack_pop(st1, &out_int) == 1);
    assert(stack_find_min(st1, &min) == -1);
    assert(stack_show(st1) == 1);

    assert(stack_push(st1, 4) == 1);
    assert(stack_find_min(st1, &min) == 1);
    assert(min == 4);

    assert(stack_push(st1, 3) == 1);
    assert(stack_find_min(st1, &min) == 1);
    assert(min == 3);

    assert(stack_push(st1, 3) == 1);
    assert(stack_find_min(st1, &min) == 1);
    assert(min == 3);

    assert(stack_pop(st1, &out_int) == 1);
    assert(stack_find_min(st1, &min) == 1);
    assert(min == 3);

    assert(stack_pop(st1, &out_int) == 1);
    assert(stack_find_min(st1, &min) == 1);
    assert(min == 4);

    assert(stack_free(st1) == 1);
    puts("=======TEST STACK_2: SUCCESS========");
}
