#ifndef DLINK_H
#define DLINK_H

typedef struct dlist_node {
    int value;
    struct dlist_node *next;
    struct dlist_node *prev;
} dlist_node;

typedef struct dlist dlist;

dlist *dlist_init(int);

int dlist_insert_head(dlist **, int);
int dlist_insert_tail(dlist **, int);
int dlist_insert_next(dlist *, dlist_node **, int);
int dlist_insert_prev(dlist *, dlist_node **, int);

dlist_node *dlist_get_head(dlist *);
dlist_node *dlist_get_tail(dlist *);
int dlist_remove_head(dlist *, int *);
int dlist_remove_tail(dlist *, int *);

int dlist_get_size(dlist *);
void dlist_show(dlist *);
void dlist_free(dlist *);

#endif
