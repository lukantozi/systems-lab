#include <stddef.h>

#ifndef HEAP_H
#define HEAP_H

typedef struct heap heap;

heap *heap_init(size_t);
int heap_push(heap *, int);
int heap_remove(heap *, int, int *);
int heap_top(heap *, int *);
int heap_pop(heap *, int *);
int heap_size(heap *, size_t *);
int heap_show(heap *);
int heap_free(heap *);

#endif
