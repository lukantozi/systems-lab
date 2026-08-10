#include "hashmap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct hashmap_node {
    const char *key;
    int value;
    hashmap_node *next;
};

struct hashmap {
    struct hashmap_node **buckets;
    size_t capacity;
    size_t size;
};

static size_t hash(const char *key) {
    size_t val = 5381;
    size_t i;
    for (i = 0; key[i]; i++) {
        val = ((val << 5) + val) + key[i];
    }
    return val;
}

hashmap *hashmap_init(size_t cap) {
    if (cap == 0) {
        fprintf(stderr, "hashmap_init: can't initiate hashmap with 0 capacity\n");
        return NULL;
    }

    hashmap *hm = malloc(sizeof(*hm));
    if (hm == NULL) {
        fprintf(stderr, "malloc: can't init hashmap\n");
        return NULL;
    }

    hm->buckets = calloc(cap, sizeof *hm->buckets);
    if (hm->buckets == NULL) {
        free(hm);
        fprintf(stderr, "calloc: can't allocate buckets\n");
        return NULL;
    }

    hm->capacity = cap;
    hm->size = 0;

    return hm;
}

int hashmap_put(hashmap *hm, const char *k, int val) {
    if (hm == NULL) {
        fprintf(stderr, "hashmap_put: hm is NULL\n");
        return -1;
    }

    if (k == NULL) {
        fprintf(stderr, "hashmap_put: k is NULL\n");
        return -1;
    }

    size_t hashed = hash(k) % hm->capacity;
    hashmap_node *node;

    if (hm->buckets[hashed]) {
        node = hm->buckets[hashed];
        while (node) {
            if (strcmp(k, node->key) == 0) {
                node->value = val;
                return 1;
            }
            node = node->next;
        }
    }

    hashmap_node *hm_node = malloc(sizeof(*hm_node));
    if (hm_node == NULL) {
        fprintf(stderr, "malloc: can't add new node with value: %d\n", val);
        return -1;
    }

    *hm_node = (hashmap_node){
        .key = k,
        .value = val,
        .next = NULL,
    };

    hm_node->next = hm->buckets[hashed];
    hm->buckets[hashed] = hm_node;

    hm->size++;

    return 1;
}

int hashmap_get(const hashmap *hm, const char *k, int *val) {
    if (hm == NULL) {
        fprintf(stderr, "hashmap_get: hm is NULL\n");
        return -1;
    }

    if (hm->capacity == 0) {
        fprintf(stderr, "hashmap_get: hm->capacity is 0\n");
        return -1;
    }

    if (k == NULL) {
        fprintf(stderr, "hashmap_get: k is NULL\n");
        return -1;
    }

    if (val == NULL) {
        fprintf(stderr, "hashmap_get: val is NULL\n");
        return -1;
    }

    size_t hashed = hash(k) % hm->capacity;
    if (hm->buckets[hashed]) {
        hashmap_node *node = hm->buckets[hashed];
        while (node) {
            if (strcmp(k, node->key) == 0) {
                *val = node->value;
                return 1;
            }
            node = node->next;
        }
    }

    return 0;
}

/* will discard value if val == NULL */
int hashmap_remove(hashmap *hm, const char *k, int *val) {
    if (hm == NULL) {
        fprintf(stderr, "hashmap_remove: hm is NULL\n");
        return -1;
    }

    if (hm->capacity == 0) {
        fprintf(stderr, "hashmap_remove: hm->capacity is 0\n");
        return -1;
    }

    if (k == NULL) {
        fprintf(stderr, "hashmap_remove: k is NULL\n");
        return -1;
    }

    size_t hashed = hash(k) % hm->capacity;
    if (hm->buckets[hashed]) {
        hashmap_node *node = hm->buckets[hashed];
        hashmap_node *prev = node;
        while (node) {
            if (strcmp(k, node->key) == 0) {
                if (node == prev)
                    hm->buckets[hashed] = node->next;
                else 
                    prev->next = node->next;

                if (val != NULL)
                    *val = node->value;

                free(node);
                hm->size--;
                return 1;
            }
            prev = node;
            node = node->next;
        }
    }

    return 0;
}

size_t hashmap_size(const hashmap *hm) {
    if (hm == NULL) {
        fprintf(stderr, "hashmap_size: hm is NULL\n");
        return 0;
    }

    return hm->size;
}

void hashmap_free(hashmap *hm) {
    if (hm == NULL)
        return;

    hashmap_node **buckets = hm->buckets;
    for (size_t i = 0; i < hm->capacity; i++) {
        if (buckets[i]) {
            hashmap_node *tmp = buckets[i];
            hashmap_node *tmp_next;
            while (tmp) {
                tmp_next = tmp->next;
                free(tmp);
                tmp = tmp_next;
            }
        }
    }

    free(buckets);
    free(hm);
}
