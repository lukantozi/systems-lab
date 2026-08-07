#include <stddef.h>

#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct hashmap_node hashmap_node;
typedef struct hashmap hashmap;

hashmap *hashmap_init(size_t);
int hashmap_put(hashmap *, char *, int);
int hashmap_get(hashmap *, char *, int *);
void hashmap_free(hashmap *);

#endif
