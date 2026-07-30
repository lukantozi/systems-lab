#ifndef DLINK_H
#define DLINK_H

typedef struct dlist dlist;

dlist *dlist_init(int);

int dlist_insert_first(dlist **, int);
int dlist_insert_last(dlist **, int);
int dlist_insert_next(dlist **, int);
int dlist_insert_prev(dlist **, int);

int dlist_get_current(dlist *, int *);
int dlist_get_next(dlist *, int *);
int dlist_get_prev(dlist *, int *);
int dlist_get_first(dlist *, int *);
int dlist_get_last(dlist *, int *);

void dlist_show(dlist *);
void dlist_free(dlist *);

#endif
