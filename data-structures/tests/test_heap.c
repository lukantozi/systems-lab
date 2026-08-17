#include <stdio.h>
#include <assert.h>
#include "heap.h"

int main(void) {
    puts("=====TEST HEAP_1: START=====");
    heap *hp = heap_init(5);
    int out_int;
    size_t out_size;
    assert(hp != NULL);

#if 0
    assert(1 == heap_push(hp, 10));
    assert(1 == heap_size(hp, &out_size));
    assert(out_size == 1);

    assert(1 == heap_push(hp, 20));
    assert(1 == heap_size(hp, &out_size));
    assert(out_size == 2);
    assert(1 == heap_top(hp, &out_int));
    assert(out_int == 10);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 4) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 3) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 6) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 5) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 7) == 1);
    assert(heap_show(hp) == 1);
#endif
#if 0
    assert(heap_push(hp, 1) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 2) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 3) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 4) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 5) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 6) == 1);
    assert(heap_show(hp) == 1);
#endif // in order

    (void)out_size;
    assert(heap_push(hp, 6) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 5) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 4) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 3) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 2) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 1) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_remove(hp, 2, &out_int) == 1);
    assert(out_int == 2);
    assert(heap_show(hp) == 1);

    assert(heap_remove(hp, 1, &out_int) == 1);
    assert(out_int == 1);
    assert(heap_show(hp) == 1);

    assert(heap_remove(hp, 6, &out_int) == 1);
    assert(out_int == 6);
    assert(heap_show(hp) == 1);
    assert(heap_pop(hp, &out_int) == 1);
    assert(out_int == 3);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 10) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_push(hp, 1) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_remove(hp, 10, &out_int) == 1);
    assert(out_int == 10);
    assert(heap_show(hp) == 1);
    assert(heap_pop(hp, &out_int) == 1);
    assert(heap_pop(hp, &out_int) == 1);
    assert(heap_pop(hp, &out_int) == 1);
    assert(heap_show(hp) == 1);
    assert(heap_pop(hp, &out_int) == -1);

    assert(heap_push(hp, 7) == 1);
    assert(heap_pop(hp, &out_int) == 1);
    assert(heap_size(hp, &out_size) == 1);
    assert(out_size == 0);

    assert(heap_push(hp, 7) == 1);
    assert(heap_push(hp, 3) == 1);
    assert(heap_size(hp, &out_size) == 1);
    assert(out_size == 2);
    assert(heap_pop(hp, &out_int) == 1);
    assert(out_int == 3);
    assert(heap_top(hp, &out_int) == 1);
    assert(out_int == 7);
    assert(heap_size(hp, &out_size) == 1);
    assert(out_size == 1);

    heap_free(hp);
    puts("=====TEST HEAP_1: SUCESS=====");
    return 0;
}
