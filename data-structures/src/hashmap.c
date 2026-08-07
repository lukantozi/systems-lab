#include "hashmap.h"
#include <stdlib.h>
#include <stdio.h>

struct hashmap_node {
    char *key;
    int value;
    hashmap_node *next;
};

struct hashmap {
    struct hashmap_node **buckets;
    size_t capacity;
    size_t size;
};

size_t hash(char *key) {
    size_t val = 5381;
    size_t i;
    for (i = 0; key[i]; i++) {
        val = ((val << 5) + val) + key[i];
    }
    return val;
}

hashmap *hashmap_init(size_t cap) {
    hashmap *hm = malloc(sizeof(*hm));
    if (hm == NULL) {
        fprintf(stderr, "malloc: can't init hashmap\n");
        return NULL;
    }

    hm->buckets = calloc(cap, sizeof(hm->buckets));
    if (hm->buckets == NULL) {
        fprintf(stderr, "calloc: can't allocate buckets\n");
        return NULL;
    }

    hm->capacity = cap;
    hm->size = 0;

    return hm;
}

int hashmap_put(hashmap *hm, char *k, int val) {
    if (hm->size + 1 > hm->capacity * 3 / 4) {
        /* TODO: resize */
    }

    size_t hashed = hash(k) % hm->capacity;
    hashmap_node *hm_node = malloc(sizeof(*hm_node));
    if (hm_node == NULL) {
        fprintf(stderr, "malloc: can't put hashmap node with value %d\n", val);
        return 0;
    }

    *hm_node = (hashmap_node){
        .key = k,
        .value = val,
        .next = NULL,
    };
    hm->buckets[hashed] = hm_node;
    hm->size++;

    return 1;
}

int hashmap_get(hashmap *hm, char *k, int *val) {
    if (hm->capacity == 0)
        return 0;

    size_t hashed = hash(k) % hm->capacity;
    *val = hm->buckets[hashed]->value;

    return 1;
}

void hashmap_free(hashmap *hm) {
    if (hm == NULL)
        return;

    hashmap_node **buckets = hm->buckets;
    for (size_t i = 0; i < hm->capacity; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(hm);
}
