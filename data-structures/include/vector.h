#include <stddef.h>

#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector vector;

vector *vector_init(size_t);
int vector_append(vector *, int);
int vector_insert(vector *, size_t, int);
int vector_remove(vector *, size_t, int *);
int vector_pop(vector *, int *);
int vector_get(vector *, size_t, int *);
int vector_capacity(vector *, size_t *);
int vector_size(vector *, size_t *);
int vector_show(vector *);
int vector_free(vector *);

#endif
