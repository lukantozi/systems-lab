#include <stddef.h>

#ifndef HASHMAP_H
#define HASHMAP_H

typedef struct hashmap_node hashmap_node;
typedef struct hashmap hashmap;

hashmap *hashmap_init(size_t);
int hashmap_put(hashmap *, const char *, int);
int hashmap_get(hashmap *, const char *, int *);
int hashmap_remove(hashmap *, const char *, int *);
size_t hashmap_size(const hashmap *);
void hashmap_free(hashmap *);

#endif
