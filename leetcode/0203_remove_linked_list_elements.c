#include <stdio.h>
#include "linked_list.h"

struct node *removeElements(struct node *head, int val) {
    if (!head) {
        return NULL;
    }
    while (head && head->val == val) {
        head = head->next;
    }
    struct node *curr = head, *tmp = NULL;
    while (curr && curr->next) {
        if (curr->next->val == val) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

int main(void) {
    struct node *head = node_create(6);
    head->next = node_create(2);
    head->next->next = node_create(6);
    head->next->next->next = node_create(6);
    head->next->next->next->next = node_create(4);
    head->next->next->next->next->next = node_create(3);
    head->next->next->next->next->next->next = node_create(6);
    head->next->next->next->next->next->next->next = node_create(3);

    print_linked_list(head);

    print_linked_list(removeElements(head, 6));
}
