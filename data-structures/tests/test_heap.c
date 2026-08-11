#include <stdio.h>
#include <assert.h>
#include "heap.h"

int main(void) {
    puts("=====TEST HEAP_1: START=====");
    heap *hp = heap_init(5);
    int out_int;
    size_t out_size;
    assert(hp != NULL);

    assert(1 == heap_push(hp, 10));
    assert(1 == heap_size(hp, &out_size));
    assert(out_size == 1);

    assert(1 == heap_push(hp, 20));
    assert(1 == heap_size(hp, &out_size));
    assert(out_size == 2);
    assert(1 == heap_peek(hp, &out_int));
    assert(out_int == 10);

    heap_free(hp);
    puts("=====TEST HEAP_1: SUCESS=====");
    return 0;
}
