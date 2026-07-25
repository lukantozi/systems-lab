#include <stddef.h>

#ifndef LIST_H
#define LIST_H

typedef struct node node;

node *list_init(int);
void list_insert_first(node **, int);
void list_insert_last(node **, int);
int list_insert_at(node **, size_t, int);
int list_remove_first(node **, int *);
int list_remove_last(node **, int *);
int list_remove_at(node **, size_t, int *);
void list_show(node *);
void list_free(node *);

#endif
