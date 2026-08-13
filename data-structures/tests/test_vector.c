#include "vector.h"
#include <stdio.h>
#include <assert.h>

int main(void) {
#if 1
    puts("=====TEST VEC_1: START======");
    int out_int;
    size_t out_size;
    vector *vp = vector_init(10);
    assert(vp != NULL);
    assert(vector_capacity(vp, &out_size) == 1);
    assert(out_size == 10);
    assert(vector_size(vp, &out_size) == 1);
    assert(out_size == 0);

    for (int i = 1; i < 5; i++)
        assert(vector_append(vp, (i%4)*i) == 1);

    assert(vector_size(vp, &out_size) == 1);
    assert(out_size == 4);
    size_t i;
    for (i = 0; i < out_size; i++) {
        assert(vector_get(vp, i, &out_int) == 1);
        printf("vector_get: %d\n", out_int);
    }
    assert(vector_show(vp) == 1);

    assert(vector_remove(vp, 0, &out_int) == 1);
    assert(vector_capacity(vp, &out_size) == 1);
    printf("vector_remove: %d\n", out_int);
    assert(vector_show(vp) == 1);
    printf("capacity: %zu\n", out_size);
    assert(out_size == 10);
    assert(vector_size(vp, &out_size) == 1);
    assert(out_size == 3);
    printf("size: %zu\n", out_size);

    assert(vector_remove(vp, 0, &out_int) == 1);
    assert(vector_capacity(vp, &out_size) == 1);
    printf("vector_remove: %d\n", out_int);
    assert(vector_show(vp) == 1);
    printf("capacity: %zu\n", out_size);
    assert(out_size == 10);
    assert(vector_size(vp, &out_size) == 1);
    assert(out_size == 2);
    printf("size: %zu\n", out_size);

    assert(vector_remove(vp, 0, &out_int) == 1);
    assert(vector_capacity(vp, &out_size) == 1);
    printf("vector_remove: %d\n", out_int);
    assert(vector_show(vp) == 1);
    printf("capacity: %zu\n", out_size);
    assert(out_size == 5);
    assert(vector_size(vp, &out_size) == 1);
    assert(out_size == 1);
    printf("size: %zu\n", out_size);

    assert(vector_remove(vp, 0, &out_int) == 1);
    assert(vector_capacity(vp, &out_size) == 1);
    printf("vector_remove: %d\n", out_int);
    assert(vector_show(vp) == 1);
    printf("capacity: %zu\n", out_size);
    assert(out_size == 2);
    assert(vector_size(vp, &out_size) == 1);
    assert(out_size == 0);
    printf("size: %zu\n", out_size);

    assert(vector_show(vp) == 1);
    assert(vector_remove(vp, 1, &out_int) == -1);
    assert(vector_size(vp, &out_size) == 1);
    assert(out_size == 0);
    assert(vector_get(vp, 2, &out_int) == -1);
    assert(vector_size(vp, &out_size) == 1);
    assert(out_size == 0);

    assert(vector_insert(vp, 0, 5) == 1);
    assert(vector_insert(vp, 1, 55) == 1);
    assert(vector_get(vp, 1, &out_int) == 1);
    assert(out_int == 55);
    assert(vector_remove(vp, 1, &out_int) == 1);
    assert(out_int == 55);
    assert(vector_get(vp, 1, &out_int) == -1);
    assert(vector_size(vp, &out_size) == 1);
    assert(out_size == 1);
    assert(vector_show(vp) == 1);

    assert(vector_capacity(vp, &out_size) == 1);
    printf("capacity: %zu\n", out_size);
    assert(out_size == 2);
    assert(vector_size(vp, &out_size) == 1);
    assert(out_size == 1);
    assert(vector_append(vp, 13) == 1);
    assert(vector_get(vp, 1, &out_int) == 1);
    assert(out_int == 13);
    assert(vector_show(vp) == 1);

    assert(vector_capacity(vp, &out_size) == 1);
    assert(out_size == 2);
    assert(vector_size(vp, &out_size) == 1);
    assert(out_size == 2);

    assert(vector_append(vp, 23) == 1);
    assert(vector_capacity(vp, &out_size) == 1);
    assert(out_size == 4);
    assert(vector_size(vp, &out_size) == 1);
    assert(out_size == 3);
    assert(vector_show(vp) == 1);
    assert(vector_pop(vp, &out_int) == 1);
    assert(out_int == 23);
    assert(vector_pop(vp, &out_int) == 1);
    assert(out_int == 13);
    assert(vector_pop(vp, &out_int) == 1);
    assert(out_int == 5);
    assert(vector_pop(vp, &out_int) == -1);
    assert(vector_size(vp, &out_size) == 1);
    assert(out_size == 0);

    assert(vector_free(vp) == 1);
    puts("=====TEST VEC_1: SUCESS=====");
    putchar('\n');
#endif // VEC_1
    
#if 1
    puts("=====TEST VEC_2: START======");
    assert(vector_init(0) == NULL);
    vector *vp1 = vector_init(8);
    assert(vp1 != NULL);
    for (size_t i = 1; i < 4; i++)
        assert(vector_append(vp1, i) == 1);

    assert(vector_show(vp1) == 1);
    assert(vector_size(vp1, &out_size) == 1);
    printf("size: %zu\n", out_size);
    assert(out_size == 3);
    assert(vector_capacity(vp1, &out_size) == 1);
    printf("capacity: %zu\n", out_size);
    assert(out_size == 8);

    assert(vector_pop(vp1, &out_int) == 1);
    assert(vector_show(vp1) == 1);
    assert(vector_size(vp1, &out_size) == 1);
    printf("size: %zu\n", out_size);
    assert(out_size == 2);
    assert(vector_capacity(vp1, &out_size) == 1);
    printf("capacity: %zu\n", out_size);
    assert(out_size == 8);

    assert(vector_pop(vp1, &out_int) == 1);
    assert(vector_show(vp1) == 1);
    assert(vector_size(vp1, &out_size) == 1);
    printf("size: %zu\n", out_size);
    assert(out_size == 1);
    assert(vector_capacity(vp1, &out_size) == 1);
    printf("capacity: %zu\n", out_size);
    assert(out_size == 4);

    assert(vector_free(vp1) == 1);
    puts("=====TEST VEC_2: SUCESS=====");
#endif // VEC_2

#if 0
    puts("=====TEST VEC_3: START======");
    puts("=====TEST VEC_3: SUCCESS======");
#endif // VEC_3
}
