#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (!head || !head->next) {
        return 0;
    }
    struct ListNode *fast = head->next;
    while (fast != head) {
        if (!fast || !(fast->next)) return 0;
        fast = fast->next->next;
        head = head->next;
    }
    return 1;
}

struct ListNode *node_create(int value) {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    if (!node) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }
    node->val = value;
    node->next = NULL;
    return node;
}

int main(void) {
    struct ListNode *head = node_create(10);
    head->next = node_create(20);
    head->next->next = node_create(30);
    head->next->next->next = node_create(40);
    head->next->next->next = head->next;

    struct ListNode *head2 = node_create(11);
    head2->next = node_create(22);
//    head2->next = head2;
    printf("%d\n", hasCycle(head2));
    printf("%d\n", hasCycle(head));
}

