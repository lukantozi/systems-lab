#include <stdlib.h>
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
