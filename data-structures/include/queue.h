#include <stddef.h>

#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue queue;

queue *queue_init(size_t);
int queue_is_full(queue *);
int queue_is_empty(queue *);
int queue_enqueue(queue *, int);
int queue_dequeue(queue *, int *);
int queue_peek(queue *, int *);
int queue_show(queue *);
void queue_free(queue *);

#endif
