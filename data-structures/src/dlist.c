#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>

struct dlist {
    int size;
    dlist_node *head;
    dlist_node *tail;
};

dlist *dlist_init(int val) {
    dlist *dp = malloc(sizeof(*dp));
    if (dp == NULL) 
        return NULL;

    dlist_node *dnp = malloc(sizeof(*dnp));
    if (dnp == NULL) {
        free(dp);
        return NULL;
    }

    dnp->value = val;
    dnp->next = NULL;
    dnp->prev = NULL;

    dp->head = dnp;
    dp->tail = dnp;
    dp->size = 1;

    return dp;
}

int dlist_insert_head(dlist **dp, int val) {
    dlist_node *dnp = malloc(sizeof(*dnp));
    if (dnp == NULL) {
        fprintf(stderr, "couldn't insert value: %d\n", val);
        return 0;
    }

    /* wire new node into list */
    dnp->next = (*dp)->head;
    dnp->prev = NULL;
    dnp->value = val;
    (*dp)->head->prev = dnp;

    /* update list head */
    (*dp)->head = dnp;
    (*dp)->size++;

    return 1;
}

int dlist_insert_tail(dlist **dp, int val) {
    dlist_node *dnp = malloc(sizeof(*dnp));
    if (dnp == NULL) {
        fprintf(stderr, "couldn't insert value: %d\n", val);
        return 0;
    }

    /* wire new node into list */
    dnp->prev = (*dp)->tail;
    dnp->next = NULL;
    dnp->value = val;
    (*dp)->tail->next = dnp;

    /* update list tail */
    (*dp)->tail = dnp;
    (*dp)->size++;

    return 1;
}

int dlist_insert_next(dlist *dp, dlist_node **dnp, int val) {
    dlist_node *dpnew = malloc(sizeof(*dpnew));
    if (dpnew == NULL) {
        fprintf(stderr, "couldn't insert value: %d\n", val);
        return 0;
    }

    /* wire new node into list */
    dlist_node *tmp_next = (*dnp)->next;
    dpnew->next = tmp_next;
    dpnew->prev = *dnp;
    dpnew->value = val;

    /* update tail if necessary */
    if (tmp_next == NULL)
        dp->tail = dpnew;
    else
        tmp_next->prev = dpnew;

    (*dnp)->next = dpnew;
    dp->size++;

    return 1;
}

int dlist_insert_prev(dlist *dp, dlist_node **dnp, int val) {
    dlist_node *dpnew = malloc(sizeof(*dpnew));
    if (dpnew == NULL) {
        fprintf(stderr, "couldn't insert value: %d\n", val);
        return 0;
    }

    /* wire new node into list */
    dlist_node *tmp_prev = (*dnp)->prev;
    dpnew->prev = tmp_prev;
    dpnew->next = *dnp;
    dpnew->value = val;

    /* update head if necessary */
    if (tmp_prev == NULL)
        dp->head = dpnew;

    (*dnp)->prev = dpnew;
    dp->size++;

    return 1;
}

dlist_node *dlist_get_head(dlist *dp) {
    if (dp == NULL) 
        return NULL;
    return dp->head;
}

dlist_node *dlist_get_tail(dlist *dp) {
    if (dp == NULL) 
        return NULL;
    return dp->tail;
}

int dlist_remove_head(dlist *dp, int *ret) {
    if (dp == NULL || dp->head == NULL)
        return 0;

    *ret = dp->head->value;
    if (dp->head->next == NULL) {
        free(dp->head);
        dp->head = NULL;
        dp->tail = NULL;
        dp->size = 0;
    } else {
        dlist_node *tmp = dp->head;
        dlist_node *tmp_next = dp->head->next;
        tmp_next->prev = NULL;
        free(tmp);
        dp->head = tmp_next;
        dp->size--;
    }

    return 1;
}

int dlist_remove_tail(dlist *dp, int *ret) {
    if (dp == NULL || dp->tail == NULL)
        return 0;

    *ret = dp->tail->value;
    if (dp->tail->prev == NULL) {
        free(dp->tail);
        dp->head = NULL;
        dp->tail = NULL;
        dp->size = 0;
    } else {
        dlist_node *tmp = dp->tail;
        dlist_node *tmp_prev = dp->tail->prev;
        tmp_prev->next = NULL;
        free(tmp);
        dp->tail = tmp_prev;
        dp->size--;
    }

    return 1;
}

int dlist_get_size(dlist *dp) {
    if (dp == NULL)
        return -1;
    return dp->size;
}

void dlist_show(dlist *dp) {
    if (dp == NULL)
        return;

    printf("NULL");
    dlist_node *tmp = dp->head;
    while (tmp) {
        printf(" <- %d -> ", tmp->value);
        tmp = tmp->next;
    }
    puts("NULL");
}

void dlist_free(dlist *dp) {
    if (dp == NULL)
        return;
    dlist_node *tmp_node;
    while (dp->head) {
        tmp_node = dp->head->next;
        free(dp->head);
        dp->head = tmp_node;
    }
    free(dp);
}
