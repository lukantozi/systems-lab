#include "list.h"
#include <stdio.h>
#include <assert.h>

int main(void) {
    node *n = list_init(2);
    int out;

    list_remove_last(&n, &out);
    assert(n == NULL);
    assert(out == 2);

    list_insert_first(&n, 4);
    list_insert_at(&n, 1, 6);
    list_insert_first(&n, 8);
    list_show(n);

    list_remove_at(&n, 2, &out);
    assert(out == 6);
    list_show(n);

    list_remove_first(&n, &out);
    assert(out == 8);
    list_show(n);

    list_remove_last(&n, &out);
    assert(out == 4);
    list_show(n);

    assert(0 == list_insert_at(&n, 5, 10));
    list_remove_first(&n, &out);
    list_show(n);
    list_insert_last(&n, 20);
    list_show(n);

    list_free(n);
}
