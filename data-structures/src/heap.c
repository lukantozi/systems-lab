#include "heap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

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

    size_t ind;
    if (vector_size(hpt->storage, &ind) == -1)
        return -1;

    if (vector_append(hpt->storage, val) == -1)
        return -1;

    int above;
    if (ind > 0) {
        do {
            if (vector_get(hpt->storage, (ind - 1) / 2, &above) == -1)
                return -1;

            if (above > val) {
                if (vector_swap(hpt->storage, ind, (ind - 1) / 2)  == -1)
                    return -1;
            } else {
                return 1;
            }

            ind = (ind - 1) / 2;
        } while (ind > 0);
    }

    return 1;
}

int heap_remove(heap *hpt, int val, int *ret) {
    if (hpt == NULL)
        HEAP_NULL_ERROR("remove", "hpt", -1);

    if (ret == NULL)
        HEAP_NULL_ERROR("remove", "ret", -1);

    size_t i = 0, siz;
    if (vector_size(hpt->storage, &siz) == -1)
        return -1;

    int cur;
    while (i < siz) {
        if (vector_get(hpt->storage, i, &cur) == -1)
            return -1;
        if (cur == val)
            break;
        i++;
    }

    if (i == siz)
        return -1;

    if (i == siz - 1) {
        if (vector_pop(hpt->storage, ret) == -1)
            return -1;
        return 1;
    }

    if (vector_get(hpt->storage, siz - 1, &cur) == -1)
        return -1;
    if (vector_swap(hpt->storage, siz-1, i) == -1)
        return -1;
    if (vector_pop(hpt->storage, ret) == -1)
        return -1;

    siz--;
    int above;
    if (i > 0) {
        if (vector_get(hpt->storage, (i - 1) / 2, &above) == -1)
            return -1;
    }
    if (i > 0 && above > cur) {
        do {
            if (vector_get(hpt->storage, (i - 1) / 2, &above) == -1)
                return -1;

            if (above > cur) {
                if (vector_swap(hpt->storage, i, (i - 1) / 2)  == -1)
                    return -1;
            } else {
                return 1;
            }
            i = (i - 1) / 2;
        } while (i > 0);
    } else {
        size_t left, right, smallest;
        int left_val, right_val, smallest_val;
        while (1) {
            left  = 2 * i + 1;
            right = 2 * i + 2;
            smallest = i;

            if (vector_get(hpt->storage, smallest, &smallest_val) == -1)
                return -1;

            if (left < siz) {
                if (vector_get(hpt->storage, left, &left_val) == -1)
                    return -1;
                if (left_val < smallest_val) {
                    smallest = left;
                    smallest_val = left_val;
                }
            }

            if (right < siz) {
                if (vector_get(hpt->storage, right, &right_val) == -1)
                    return -1;
                if (right_val < smallest_val) {
                    smallest = right;
                    smallest_val = right_val;
                }
            }

            if (smallest != i) {
                if (vector_swap(hpt->storage, i, smallest) == -1)
                    return -1;
                i = smallest;
            } else {
                break;
            }
        }
    }

    return 1;
}

int heap_top(heap *hpt, int *pkd) {
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

int heap_show(heap *hpt) {
    if (hpt == NULL)
        HEAP_NULL_ERROR("show", "hpt", -1);

    if (vector_show(hpt->storage) == -1)
        return -1;

    return 1;
}

int heap_free(heap *hpt) {
    if (hpt == NULL)
        HEAP_NULL_ERROR("free", "hpt", -1);

    vector_free(hpt->storage);
    free(hpt);
    return 1;
}
