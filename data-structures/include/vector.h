#include <stddef.h>

#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector vector;
vector *vector_init(size_t);
int vector_append(vector *, int);
int vector_get(vector *, size_t);
size_t vector_capacity(vector *);
size_t vector_size(vector *);
void vector_show(vector *);
void vector_free(vector *);

#endif
