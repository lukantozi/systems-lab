#include "vector.h"
#include "stdio.h"
#include "assert.h"

int main(void) {
    /* test vec: append, get_size_inmem/inuse show_array*/
    vector *vec = init_vector(5);
    int status;
    for (size_t i = 0; i < 10; i++) {
        status = append_element(vec, i);
        assert(status == 1);
    }

    assert(11 == get_size_inmem(vec));
    assert(10 == get_size_inuse(vec));
    show_array(vec);

    append_element(vec, 10);
    assert(11 == get_size_inmem(vec));
    assert(11 == get_size_inuse(vec));
    show_array(vec);

    append_element(vec, 11);
    assert(23 == get_size_inmem(vec));
    assert(12 == get_size_inuse(vec));
    show_array(vec);

    /* test vec1: all above + get_element */
    vector *vec1 = init_vector(10);
    append_element(vec1, 5);
    append_element(vec1, 10);
    append_element(vec1, 15);
    assert(10 == get_size_inmem(vec1));
    assert(3 == get_size_inuse(vec1));
    show_array(vec1);
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += get_element(vec1, i);
    }
    assert(sum == 30);

    /* free vecs */
    free_vector(vec);
    free_vector(vec1);
}
