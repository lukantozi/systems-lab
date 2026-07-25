#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

node *list_init(int val) {
    node *n = malloc(sizeof(*n));
    if (n == NULL) return NULL;

    n->value = val;
    n->next = NULL;

    return n;
}

void list_insert_first(node **head, int val) {
    node *n = list_init(val);
    if (n == NULL) {
        fprintf(stderr, "couldn't insert value: %d\n", val);
        return;
    }
    n->next = *head;
    *head = n;
}

void list_insert_last(node **head, int val) {
    node *n = list_init(val);
    if (n == NULL) {
        fprintf(stderr, "couldn't insert value: %d\n", val);
        return;
    }

    if (*head == NULL) *head = n;
    else {
        node *tmp = *head;
        while (tmp->next) tmp = tmp->next;
        tmp->next = n;
    }
}

int list_insert_at(node **head, size_t index, int val) {
    if (index == 0) {
        list_insert_first(head, val);
        return 1;
    }

    if (*head == NULL) {
        fprintf(stderr, "cannot insert at index %zu: list is empty\n", index);
        return 0;
    }

    node *tmp = *head;
    for (size_t i = 0; tmp != NULL && i < index - 1; i++) tmp = tmp->next;
    if (tmp == NULL) {
        fprintf(stderr, "%zu: index out of list range\n", index);
        return 0;
    }

    node *n = list_init(val);
    if (n == NULL) {
        fprintf(stderr, "couldn't insert value: %d\n", val);
        return 0;
    }

    node *tmp_next = tmp->next;
    tmp->next = n;
    n->next = tmp_next;
    return 1;
}

int list_remove_first(node **head, int *val) {
    if (*head == NULL) {
        fprintf(stderr, "cannot remove first: list is empty\n");
        return 0;
    }

    *val = (*head)->value;

    node *tmp = (*head)->next;
    free(*head);
    *head = tmp;
    return 1;
}

int list_remove_last(node **head, int *val) {
    if (*head == NULL) {
        fprintf(stderr, "cannot remove last: list is empty\n");
        return 0;
    }

    if ((*head)->next == NULL) {
        *val = (*head)->value;
        free(*head);
        *head = NULL;
        return 1;
    }

    node *tmp = *head;
    while (tmp->next->next) {
        tmp = tmp->next;
    }

    *val = tmp->next->value;
    free(tmp->next);
    tmp->next = NULL;

    return 1;
}

int list_remove_at(node **head, size_t index, int *val) {
    if (*head == NULL) {
        fprintf(stderr, "cannot remove index %zu: list is empty\n", index);
        return 0;
    }

    if (index == 0) {
        list_remove_first(head, val);
        return 1;
    }

    node *tmp = *head;
    for (size_t i = 0; tmp != NULL && i < index - 1; i++) tmp = tmp->next;
    if (tmp == NULL) {
        fprintf(stderr, "%zu: index out of list range\n", index);
        return 0;
    }

    if (tmp->next == NULL) {
        fprintf(stderr, "%zu: index out of list range\n", index);
        return 0;
    }

    *val = tmp->next->value;
    node *tmp_next = tmp->next->next;
    free(tmp->next);
    tmp->next = tmp_next;
    return 1;
}

void list_show(node *head) {
    while (head) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    puts("NULL");
}

void list_free(node *n) {
    node *tmp;
    while (n) {
        tmp = n->next;
        free(n);
        n = tmp;
    }
}
