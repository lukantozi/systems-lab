#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    int val;
    struct node *next;
};

struct node *node_create(int value);

#endif
