#include "vector.h"
#include "stdio.h"
#include "assert.h"

int main(void) {
    vector *vec = init_vector(5);
    int status;
    for (size_t i = 0; i < 10; i++) {
        status = append_element(vec, i);
        assert(status == 1);
    }

    printf("\nsize of vec: %zu\n", get_size_inmem(vec));
    printf("elements in use in vec: %zu\n", get_size_inuse(vec));
    show_array(vec);

    puts("\nappend 10");
    append_element(vec, 10);
    printf("size of vec: %zu\n", get_size_inmem(vec));
    printf("elements in use in vec: %zu\n", get_size_inuse(vec));
    show_array(vec);

    puts("\nappend 11");
    append_element(vec, 11);
    printf("size of vec: %zu\n", get_size_inmem(vec));
    printf("elements in use in vec: %zu\n\n", get_size_inuse(vec));
    show_array(vec);

    // assert(get_element(vec, 12) == 1);


#if 1
    size_t len = get_size_inuse(vec);
    for (size_t i = 0; i < len; i++) {
        printf("at index %zu: %d\n", i, get_element(vec, i));
    }
    show_array(vec);

    vector *vec1 = init_vector(10);
    append_element(vec1, 5);
    append_element(vec1, 10);
    append_element(vec1, 15);
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += get_element(vec1, i);
    }
    show_array(vec1);
    printf("%d\n", sum);
    free_vector(vec1);
#endif

    free_vector(vec);
}
