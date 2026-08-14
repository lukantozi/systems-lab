#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct dict {
    int *values;
    int *keys;
    size_t size;
    size_t capacity;
} dict;

dict *dict_init(size_t max) {
    dict *d = malloc(sizeof(*d));
    if (d == NULL)
        return NULL;

    d->values = calloc(max + 1, sizeof(int));
    if (d->values == NULL) {
        free(d);
        return NULL;
    }

    d->keys = calloc(max + 1, sizeof(int));
    if (d->keys == NULL) {
        free(d->values);
        free(d);
        return NULL;
    }
    d->capacity = max;
    d->size = 0;

    return d;
}

int dict_insert(dict *d, int key, int x) {
    if (d == NULL)
        return -1;

    if (key > d->capacity || key <= 0) {
        fprintf(stderr, "key %d out of range: 1 - %zu\n", key, d->capacity);
        return -1;
    }

    if (x > d->capacity || x <= 0) {
        fprintf(stderr, "value %d out of range: 1 - %zu\n", x, d->capacity);
        return -1;
    }

    if (d->size == d->capacity) {
        fprintf(stderr, "dict is full\n");
        return -1;
    }
    
    if (d->keys[x]) {
        fprintf(stderr, "value %d already in dict\n", x);
        return -1;
    }

    if (d->values[key]) {
        d->keys[d->values[key]] = 0;
        d->keys[x] = key;
        d->values[key] = x;
    } else {
        d->size++;
        d->keys[x] = key;
        d->values[key] = x;
    }

    return 1;
}

int dict_remove(dict *d, int x, int *out) {
    if (d == NULL || out == NULL)
        return -1;

    if (x > d->capacity || x <= 0) {
        fprintf(stderr, "value %d out of range: 1 - %zu\n", x, d->capacity);
        return -1;
    }

    if (d->keys[x]) {
        size_t ind = d->keys[x];
        *out = d->keys[x];
        d->keys[x] = 0;
        d->values[ind] = 0;
        d->size--;
        return 1;
    }

    return -1;
}

int dict_search(dict *d, int x, int *ind) {
    if (d == NULL || ind == NULL)
        return -1;

    if (x > d->capacity || x <= 0) {
        fprintf(stderr, "value %d out of range: 1 - %zu\n", x, d->capacity);
        return -1;
    }

    if (d->keys[x]) {
        *ind = d->keys[x];
        return 1;
    }

    return -1;
}

int dict_free(dict *d) {
    if (d == NULL)
        return -1;

    free(d->values);
    free(d->keys);
    free(d);
    return 1;
}

int main(void) {
    dict *d = dict_init(20);
    assert(d != NULL);
    assert(d->size == 0);
    int out;

    assert(dict_insert(d, 21, 5) == -1);
    assert(dict_insert(d, 5, 25) == -1);
    assert(dict_insert(d, 0, 25) == -1);
    assert(dict_insert(d, 10, 0) == -1);
    assert(dict_insert(d, 10, -1) == -1);
    assert(dict_insert(d, -1, 15) == -1);
    assert(dict_search(d, -1, &out) == -1);
    assert(dict_search(d, 0, &out) == -1);
    assert(dict_search(d, 21, &out) == -1);
    assert(dict_remove(d, -1, &out) == -1);
    assert(dict_remove(d, 0, &out) == -1);
    assert(dict_remove(d, 21, &out) == -1);

    assert(dict_insert(d, 3, 10) == 1);
    assert(d->size == 1);
    assert(dict_insert(d, 3, 10) == -1);
    assert(d->size == 1);
    assert(dict_search(d, 10, &out) == 1);
    assert(out == 3);

    assert(dict_remove(d, 10, &out) == 1);
    assert(out == 3);
    assert(d->size == 0);
    assert(dict_remove(d, 5, &out) == -1);
    assert(dict_search(d, 5, &out) == -1);

    assert(dict_insert(d, 3, 12) == 1);
    assert(d->size == 1);
    assert(dict_insert(d, 3, 11) == 1);
    assert(d->size == 1);
    assert(dict_search(d, 11, &out) == 1);
    assert(out == 3);
    assert(dict_search(d, 12, &out) == -1);
    assert(out == 3);

   assert(dict_free(d) == 1);
}
