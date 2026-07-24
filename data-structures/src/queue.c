#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

struct queue {
    int *arr;
    size_t size;
    size_t capacity;
    size_t head;
    size_t tail;
};

static void queue_empty_error(void) {
    fprintf(stderr, "queue empty: can't dequeue/peek an empty queue\n");
    exit(EXIT_FAILURE);
}

queue *queue_init(size_t cap) {
    if (cap == 0) return NULL;

    queue *q = malloc(sizeof *q);
    if (q == NULL) return NULL;

    q->arr = malloc(sizeof(int) * cap);
    if (q->arr == NULL) {
        free(q);
        return NULL;
    }

    q->capacity = cap;
    q->size = 0;
    q->head = 0;
    q->tail = 0;
    return q;
}

int queue_is_full(queue *q) {
    return q->size == q->capacity;
}

int queue_is_empty(queue *q) {
    return q->size == 0;
}

int queue_enqueue(queue *q, int item) {
    if (queue_is_full(q)) {
        fprintf(stderr, "queue full: can't enqueue item: %d\n", item);
        exit(EXIT_FAILURE);
    }

    *(q->arr + q->tail) = item;
    q->tail = (q->tail + 1) % q->capacity;
    q->size++;
    return 1;
}

int queue_dequeue(queue *q, int *deq) {
    if (queue_is_empty(q)) queue_empty_error();

    *deq = *(q->arr + q->head);
    q->head = (q->head + 1) % q->capacity;
    q->size--;
    return 1;
}

int queue_peek(queue *q, int *pkd) {
    if (queue_is_empty(q)) queue_empty_error();

    *pkd = *(q->arr + q->head);
    return 1;
}

int queue_show(queue *q) {
    if (queue_is_empty(q)) queue_empty_error();

    size_t i, offset;
    for (i = 0; i < q->size; i++) {
        offset = (q->head + i) % q->capacity;
        printf("%d ", *(q->arr + offset));
    }
    putchar('\n');

    return 1;
}

void queue_free(queue *q) {
    free(q->arr);
    free(q);
}
