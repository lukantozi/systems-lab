#include "dlist.h"
#include <stddef.h>
#include <stdio.h>
#include <assert.h>

int main(void) {
    int out;
    dlist *dp = dlist_init(5);
    dlist_show(dp);
    
    dlist_node *head = dlist_get_head(dp);
    dlist_node *tail = dlist_get_head(dp);
    assert(5 == head->value);
    assert(5 == tail->value);
    assert(1 == dlist_get_size(dp));

    dlist_insert_head(&dp, 10);
    dlist_show(dp);

    printf("new head: %d\n", head->prev->value);
    dlist_show(dp);

    dlist_insert_tail(&dp, 15);
    dlist_show(dp);

    dlist_insert_head(&dp, 20);
    dlist_show(dp);

    dlist_node *node = dlist_get_head(dp);
    node = node->next;

    dlist_insert_next(dp, &node, 11);
    dlist_show(dp);

    node = node->prev;
    dlist_insert_prev(dp, &node, 22);
    assert(1 == dlist_remove_head(dp, &out));
    printf("removed: %d\n", out);
    dlist_show(dp);

    head = dlist_get_head(dp);
    printf("new head: %d\n", head->value);

    tail = dlist_get_tail(dp);
    printf("tail: %d\n", tail->value);

    assert(1 == dlist_remove_tail(dp, &out));
    printf("removed: %d\n", out);

    dlist_show(dp);
    tail = dlist_get_tail(dp);
    printf("new tail: %d\n", tail->value);

    dlist_remove_tail(dp, &out);
    dlist_show(dp);
    tail = dlist_get_tail(dp);
    printf("new tail: %d\n", tail->value);

    dlist_remove_tail(dp, &out);
    dlist_show(dp);
    tail = dlist_get_tail(dp);
    printf("new tail: %d\n", tail->value);

    dlist_free(dp);
}
