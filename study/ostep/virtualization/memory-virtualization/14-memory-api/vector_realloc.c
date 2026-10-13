#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int *arr;
    size_t size;
    size_t cap;
} vector;

vector *vector_init(size_t cap)
{
    if (cap == 0)
        cap = 1;

    vector *vec = malloc(sizeof(*vec));
    if (vec == NULL)
        return NULL;

    vec->arr = malloc(cap * sizeof(int));
    if (vec->arr == NULL) {
        free(vec);
        return NULL;
    }

    vec->cap = cap;
    vec->size = 0;

    return vec;
}

int vector_grow(vector *ptr)
{
    if (ptr == NULL)
        return -1;

    size_t new_cap = 2 * ptr->cap;
    int *new_arr = realloc(ptr->arr, sizeof(int) * new_cap);
    if (new_arr == NULL)
        return -1;

    ptr->arr = new_arr;
    ptr->cap = new_cap;

    return 1;
}

int vector_free(vector *ptr)
{
    if (ptr == NULL)
        return -1;

    free(ptr->arr);
    free(ptr);
    return 1;
}

int main(void)
{
    vector *v = vector_init(10);
    if (v == NULL)
        return 1;

    for (size_t i = 0; i < 15; i++) {
        if (v->size == v->cap) {
            if (vector_grow(v) == -1) {
                vector_free(v);
                return 1;
            }
        }
        v->arr[i] = (int)i;
        v->size++;
    }
    printf("%zu - %zu\n", v->size, v->cap);
    vector_free(v);
}
