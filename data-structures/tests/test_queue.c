#include "queue.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
    queue *q = queue_init(5);
    assert(q != NULL);

    assert(1 == queue_is_empty(q));
    int out, in;
    for (int i = 0; i < 5; ++i) {
        in = (i+1)*2 + 1;
        queue_enqueue(q, in);
        printf("added: %d \n", in);
        printf("current queue: ");
        queue_show(q);
        putchar('\n');
    }

    queue_show(q);
    queue_dequeue(q, &out);
    assert(3 == out);
    queue_show(q);
    queue_dequeue(q, &out);
    assert(5 == out);
    queue_show(q);

    queue_enqueue(q, 20);
    queue_show(q);
    queue_enqueue(q, 22);
    queue_show(q);

    assert(1 == queue_is_full(q));

    queue_free(q);
}
