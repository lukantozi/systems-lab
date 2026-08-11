#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

#define HEAP_NULL_ERROR(x, y, z) \
    do { \
        fprintf(stderr, "heap_%s: %s is NULL", x, y); \
        return z; \
    } while (0)

struct heap {
    vector *storage;
};

/* returns NULL if vector allocation failed */
heap *heap_init(size_t cap) {
    heap *hpt = malloc(sizeof(*hpt));
    if (hpt == NULL)
        HEAP_NULL_ERROR("init", "hpt", NULL);

    vector *vpt = vector_init(cap);
    if (vpt == NULL) {
        free(hpt);
        HEAP_NULL_ERROR("init", "vpt", NULL);
    }

    hpt->storage = vpt;
    return hpt;
}

int heap_push(heap *hpt, int val) {
    if (hpt == NULL)
        HEAP_NULL_ERROR("push", "hpt", -1);
    /* find val's position in heap */
    size_t pos;
    if (vector_size(hpt->storage, &pos) == -1)
        return -1;

    return vector_insert(hpt->storage, pos, val);
}

int heap_peek(heap *hpt, int *pkd) {
    if (hpt == NULL)
        HEAP_NULL_ERROR("peek", "hpt", -1);

    if (pkd == NULL)
        HEAP_NULL_ERROR("peek", "pkd", -1);

    return vector_get(hpt->storage, 0, pkd);
}

int heap_size(heap *hpt, size_t *siz) {
    if (hpt == NULL)
        HEAP_NULL_ERROR("size", "hpt", -1);

    if (siz == NULL)
        HEAP_NULL_ERROR("size", "siz", -1);

    return vector_size(hpt->storage, siz);
}

int heap_free(heap *hpt) {
    if (hpt == NULL)
        HEAP_NULL_ERROR("free", "hpt", -1);

    vector_free(hpt->storage);
    free(hpt);
    return 1;
}
