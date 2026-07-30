#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>

struct dlist {
    int value;
    dlist *next;
    dlist *prev;
    dlist *head;
    dlist *tail;
};

/* TODO:
 * Define ownership/invariants for head and tail.
 * Verify insert_first, insert_last, insert_next.
 * Implement insert_prev.
 */

dlist *dlist_init(int val) {
    dlist *dp = malloc(sizeof(*dp));
    if (dp == NULL) return NULL;
    dp->value = val;
    dp->next = NULL;
    dp->prev = NULL;
    dp->head = dp;
    dp->tail = dp;
    return dp;
}

int dlist_insert_first(dlist **dp, int val) {
    dlist *dpn = dlist_init(val);
    if (dpn == NULL) {
        fprintf(stderr, "couldn't insert value: %d\n", val);
        return 0;
    }
    /* wire new node into list */
    dpn->next = *dp;
    (*dp)->prev = dpn;
    /* give the new node info about list */
    dpn->tail = (*dp)->tail;
    dpn->head = (*dp)->head;
    /* update head */
    *dp = dpn;
    return 1;
}

int dlist_insert_last(dlist **dp, int val) {
    dlist *dpn = dlist_init(val);
    if (dpn == NULL) {
        fprintf(stderr, "couldn't insert value: %d\n", val);
        return 0;
    }
    /* wire new node into list */
    (*dp)->tail->next = dpn;
    dpn->prev = (*dp)->tail;
    /* give the new node info about list */
    dpn->head = (*dp)->head;
    dpn->tail = dpn;
    /* update tail */
    (*dp)->tail = dpn;
    return 1;
}

int dlist_insert_next(dlist **dp, int val) {
    dlist *dpn = dlist_init(val);
    if (dpn == NULL) {
        fprintf(stderr, "couldn't insert value: %d\n", val);
        return 0;
    }
    dlist *dpt_next = (*dp)->next;
    /* wire new node into list */
    (*dp)->next = dpn;
    dpn->next = dpt_next;
    dpn->prev = (*dp);
    if (dpt_next != NULL) dpt_next->prev = dpn;
    else { /* if inserting as last, update tail */
        (*dp)->tail = dpn;
        dpn->tail = dpn;
    }
    return 1;
}

int dlist_insert_prev(dlist **dp, int val) {
    dlist *dpn = dlist_init(val);
    if (dpn == NULL) {
        fprintf(stderr, "couldn't insert value: %d\n", val);
        return 0;
    }
    dlist *dp_prev = (*dp)->prev;
    /* TODO: wire new node into list */
    return 1;
}

int dlist_get_current(dlist *dp, int *val) {
    if (dp == NULL) return 0;
    *val = dp->value;
    return 1;
}

int dlist_get_next(dlist *dp, int *val) {
    if (dp == NULL) return 0;
    if (dp->next == NULL) return -1;
    *val = dp->next->value;
    return 1;
}

int dlist_get_prev(dlist *dp, int *val) {
    if (dp == NULL) return 0;
    if (dp->prev == NULL) return -1;
    *val = dp->prev->value;
    return 1;
}

int dlist_get_first(dlist *dp, int *val) {
    if (dp == NULL) return 0;
    *val = dp->value;
    return 1;
}

int dlist_get_last(dlist *dp, int *val) {
    if (dp == NULL) return 0;
    *val = dp->tail->value;
    return 1;
}

void dlist_show(dlist *dp) {
    printf("NULL");
    while (dp) {
        printf(" <- %d -> ", dp->value);
        dp = dp->next;
    }
    puts("NULL");
}

void dlist_free(dlist *dp) {
    dlist *tdp;
    while (dp) {
        tdp = dp->next;
        free(dp);
        dp = tdp;
    }
}
