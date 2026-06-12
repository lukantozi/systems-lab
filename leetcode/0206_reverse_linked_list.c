#include <stdio.h>
#include <stdlib.h>

#define PRINT_FLAG_BEFORE 1
#define PRINT_FLAG_AFTER 1
#define RECURSE 0
#define ITERATE 1

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverseListRecurse(struct ListNode *head) {
    if (!head || !(head->next)) return head;
    struct ListNode *revh = reverseListRecurse(head->next);
    head->next->next = head;
    head->next = NULL;
    return revh;
}

struct ListNode *reverseListIter(struct ListNode *head) {
    if (!head) return NULL;
    struct ListNode *prev = NULL;
    struct ListNode *next = head->next;
    while (head) {
        head->next = prev;
        prev = head;
        if (next == NULL) break;
        head = next;
        next = head->next;
    }
    return head;
}

void print_linked_list(struct ListNode *head) {
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
}

int main(void) {
    struct ListNode *node1 = malloc(sizeof(struct ListNode));
    struct ListNode *node2 = malloc(sizeof(struct ListNode));
    struct ListNode *node3 = malloc(sizeof(struct ListNode));
    struct ListNode *node4 = malloc(sizeof(struct ListNode));
    struct ListNode *node5 = malloc(sizeof(struct ListNode));
    node1->val = 1;
    node1->next = node2;
    node2->val = 2;
    node2->next = node3;
    node3->val = 3;
    node3->next = node4;
    node4->val = 4;
    node4->next = node5;
    node5->val = 5;
    node5->next = NULL;

    struct ListNode *temp = malloc(sizeof(struct ListNode));
    temp = node1;

#if PRINT_FLAG_BEFORE
    print_linked_list(temp);
#endif

#if RECURSE
    struct ListNode *head = reverseListRecurse(node1);
#elif ITERATE
    struct ListNode *head = reverseListIter(node1);
#endif

#if PRINT_FLAG_AFTER
    print_linked_list(head);
#endif
}
