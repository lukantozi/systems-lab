#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *node_create(int value) {
    struct node *node = malloc(sizeof(struct node));
    if (!node) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = value;
    node->next = NULL;
    return node;
}

int main(void) {
    struct node *head = node_create(10);
    head->next = node_create(20);
    head->next->next = node_create(30);
    head->next->next->next = node_create(40);

    while (head) {
        printf("%d\n", head->data);
        struct node *curr = head;
        head = head->next;
        free(curr);
    }
}
