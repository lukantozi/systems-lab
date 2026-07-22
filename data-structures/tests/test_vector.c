#include "vector.h"
#include "stdio.h"
#include "assert.h"

int main(void) {
    /* test vec: append, vector_capacity/inuse vector_show*/
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

    vector_append(vec, 11);
    assert(23 == vector_capacity(vec));
    assert(12 == vector_size(vec));
    vector_show(vec);

    /* test vec1: all above + vector_get */
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

    /* free vecs */
    vector_free(vec);
    vector_free(vec1);
}
