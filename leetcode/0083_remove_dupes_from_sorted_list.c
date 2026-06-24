#include <stdio.h>
#include "linked_list.h"

struct node* deleteDuplicates(struct node* head) {
    if (head == NULL) return head;

    if (head->next && head->val == head->next->val) {
        head->next = head->next->next;
        deleteDuplicates(head);
    } else {
        deleteDuplicates(head->next);
    }

    return head;
}

int main(void) {
    struct node *test1 = node_create(1), *test = NULL;
    test1->next = node_create(1);
    test1->next->next = node_create(2);
    printf("Test 1:\n");
    test = deleteDuplicates(test1);
    print_linked_list(test);

    struct node *test2 = node_create(1);
    test2->next = node_create(1);
    test2->next->next = node_create(2);
    test2->next->next->next = node_create(3);
    test2->next->next->next->next = node_create(3);
    printf("Test 2:\n");
    test = deleteDuplicates(test2);
    print_linked_list(test);

    struct node *test3 = node_create(1);
    test3->next = node_create(1);
    test3->next->next = node_create(1);
    printf("Test 3:\n");
    test = deleteDuplicates(test3);
    print_linked_list(test);
}
