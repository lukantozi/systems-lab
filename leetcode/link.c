#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

struct node *node_create(int value) {
    struct node *node = malloc(sizeof(struct node));
    if (!node) {
        return NULL;
    }
    node->val = value;
    node->next = NULL;
    return node;
}

void print_linked_list(struct node *head) {
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
}
