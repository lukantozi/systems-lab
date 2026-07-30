#include "dlist.h"
#include <stddef.h>
#include <stdio.h>
#include <assert.h>

int main(void) {
    dlist *dp = dlist_init(5);
    int out;

    assert(dp != NULL);
    assert(-1 == dlist_get_next(dp, &out));
    assert(-1 == dlist_get_prev(dp, &out));
    assert(1 == dlist_get_current(dp, &out));
    assert(5 == out);
    dlist_show(dp);

    assert(1 == dlist_insert_next(&dp, 555));
    dlist_get_last(dp, &out);
    assert(555 == out);
    dlist_show(dp);

    assert(1 == dlist_insert_first(&dp, 10));
    assert(-1 == dlist_get_prev(dp, &out));
    assert(1 == dlist_get_next(dp, &out));
    assert(5 == out);
    assert(1 == dlist_get_current(dp, &out));
    assert(10 == out);
    dlist_get_first(dp, &out);
    assert(10 == out);
    dlist_show(dp);

    dlist_insert_last(&dp, 55);
    dlist_get_first(dp, &out);
    assert(10 == out);
    dlist_get_last(dp, &out);
    assert(55 == out);
    dlist_show(dp);

    dlist_insert_first(&dp, 20);
    dlist_get_first(dp, &out);
    assert(20 == out);
    dlist_show(dp);

    dlist_insert_next(&dp, 21);
    dlist_show(dp);

    dlist_insert_last(&dp, 33);
    dlist_get_last(dp, &out);
    assert(33 == out);
    dlist_show(dp);

    dlist_free(dp);
}
