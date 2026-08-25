#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
   int *arr;
   int *mins;
   size_t size;
   size_t cap;
} MinStack;


MinStack* minStackCreate() {
    int *a = malloc(sizeof(int)*10);
    if (a == NULL)
        return NULL;

    int *m = malloc(sizeof(int)*10);
    if (m == NULL) {
        free(a);
        return NULL;
    }
    memset(m, INT_MAX, sizeof(int) * 10);

    MinStack *obj = malloc(sizeof(*obj));
    if (obj == NULL) {
        free(a);
        free(m);
        return NULL;
    }

    obj->arr = a;
    obj->mins = m;
    obj->cap = 10;
    obj->size = 0;

    return obj;
}

void minStackPush(MinStack* obj, int value) {
    if (obj->size + 1 == obj->cap) {
        int *new_arr = realloc(obj->arr, sizeof(*new_arr) * obj->cap * 2);
        if (new_arr == NULL)
            return;

        int *new_mins = realloc(obj->mins, sizeof(*new_arr) * obj->cap * 2);
        if (new_mins == NULL) {
            free(new_arr);
            return;
        }

        obj->arr = new_arr;
        obj->mins = new_mins;
        size_t old_cap = obj->cap;
        obj->cap *= 2;
        memset(obj->mins + old_cap, INT_MAX, sizeof(int) * (obj->cap - old_cap));
    }

    obj->arr[obj->size] = value;
    if (obj->size == 0) {
        obj->mins[0] = value;
    } else {
        if (value < obj->mins[obj->size - 1])
            obj->mins[obj->size] = value;
        else
            obj->mins[obj->size] = obj->mins[obj->size - 1];
    }
    obj->size++;
}

void minStackPop(MinStack* obj) {
    obj->size--;
}

int minStackTop(MinStack* obj) {
    return obj->arr[obj->size - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->mins[obj->size - 1];
}

void minStackFree(MinStack* obj) {
    if (obj == NULL)
        return;

    free(obj->arr);
    free(obj->mins);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, value);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
