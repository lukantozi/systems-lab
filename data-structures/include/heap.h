#include <stddef.h>
#include "vector.h"

#ifndef HEAP_H
#define HEAP_H

typedef struct heap heap;

heap *heap_init(size_t);
int heap_push(heap *, int);
int heap_peek(heap *, int *);
int heap_size(heap *, size_t *);
int heap_free(heap *);

#endif
