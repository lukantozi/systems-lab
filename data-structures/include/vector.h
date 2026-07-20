#include <stddef.h>

#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector vector;
vector *init_vector(size_t);
int append_element(vector *, int);
int get_element(vector *, size_t);
size_t get_size_inmem(vector *);
size_t get_size_inuse(vector *);
void show_array(vector *);
void free_vector(vector *);

#endif
