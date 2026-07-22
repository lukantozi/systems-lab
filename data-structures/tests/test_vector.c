#include "vector.h"
#include "stdio.h"
#include "assert.h"

int main(void) {
#if 0
    puts("=====VEC==========");
    vector *vec = vector_init(5);
    int status;
    for (size_t i = 0; i < 10; i++) {
        status = vector_append(vec, i);
        assert(status == 1);
    }

    assert(11 == vector_capacity(vec));
    assert(10 == vector_size(vec));
    vector_show(vec);

    vector_append(vec, 10);
    assert(11 == vector_capacity(vec));
    assert(11 == vector_size(vec));
    vector_show(vec);
    vector_insert(vec, 5, 100);
    vector_show(vec);

    vector_append(vec, 11);
    assert(23 == vector_capacity(vec));
    assert(13 == vector_size(vec));
    vector_insert(vec, 13, 1000);
    assert(1000 == vector_get(vec, 13));
    vector_show(vec);
    int removed;
    vector_remove(vec, 0, &removed);
    vector_show(vec);
    vector_remove(vec, vector_size(vec)-2, &removed);
    vector_show(vec);
    vector_remove(vec, vector_size(vec)-2, &removed);
    vector_show(vec);
    vector_remove(vec, 4, &removed);
    vector_show(vec);
    assert(10 == vector_size(vec));
    vector_free(vec);

#endif /* test vec: append, vector_capacity/inuse vector_show +
     * remove */
    
#if 0
    puts("=====VEC1=========");
    vector *vec1 = vector_init(10);
    vector_append(vec1, 5);
    vector_append(vec1, 10);
    vector_append(vec1, 15);
    assert(10 == vector_capacity(vec1));
    assert(3 == vector_size(vec1));
    vector_show(vec1);
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += vector_get(vec1, i);
    }
    assert(sum == 30);
    vector_insert(vec1, 0, sum);
    assert(30 == vector_get(vec1, 0));
    vector_show(vec1);
    vector_free(vec1);
#endif /* test vec1: all above + vector_get - remove */

#if 0
    puts("=====VEC2=========");
//    int removed;
    vector *vec2 = vector_init(5);
    for (size_t i = 0; i < 5; i++) {
        vector_append(vec2, i * 3 + 1);
    }
    vector_show(vec2);
    printf("%zu\n", vector_capacity(vec2));
    vector_remove(vec2, 1, &removed);
    vector_show(vec2);
    vector_remove(vec2, vector_size(vec2)-1, &removed);
    vector_show(vec2);
    vector_remove(vec2, vector_size(vec2)-1, &removed);
    vector_show(vec2);
    printf("%zu\n", vector_size(vec2));
    printf("%zu\n", vector_capacity(vec2));
    vector_remove(vec2, vector_size(vec2)-1, &removed);
    vector_show(vec2);
    printf("%zu\n", vector_size(vec2));
    printf("%zu\n", vector_capacity(vec2));

    //vector_remove(vec2, vector_size(vec2)-1, &removed);
    vector_remove(vec2, vector_size(vec2)-1, &removed);
    vector_show(vec2);
    printf("%zu\n", vector_size(vec2));
    printf("%zu\n", vector_capacity(vec2));
    vector_append(vec2, 1);
    vector_show(vec2);
    vector_append(vec2, 1);
    vector_show(vec2);
    printf("%zu\n", vector_size(vec2));
    printf("%zu\n", vector_capacity(vec2));
    vector_append(vec2, 1);
    vector_show(vec2);
    printf("%zu\n", vector_size(vec2));
    printf("%zu\n", vector_capacity(vec2));
    vector_append(vec2, 1);
    vector_show(vec2);
    printf("%zu\n", vector_size(vec2));
    printf("%zu\n", vector_capacity(vec2));
    vector_free(vec2);
#endif

#if 1
    int popped;
    vector *vec3 = vector_init(5);
    for (int i = 0; i < 5; i++) {
        vector_append(vec3, i * 2 + 1);
    }
    vector_show(vec3);
    vector_pop(vec3, &popped);
    assert(9 == popped);
    vector_show(vec3);
    vector_pop(vec3, &popped);
    assert(7 == popped);
    vector_show(vec3);
    vector_pop(vec3, &popped);
    assert(5 == popped);
    vector_show(vec3);
    vector_pop(vec3, &popped);
    assert(3 == popped);
    vector_show(vec3);
    vector_pop(vec3, &popped);
    assert(1 == popped);
    vector_show(vec3);
    assert(vector_size(vec3) == 0);

    vector_free(vec3);
#endif /* test vector_pop() */
}
