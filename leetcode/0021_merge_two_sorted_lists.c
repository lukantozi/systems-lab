#include <stdio.h>
#include "linked_list.h"

struct node* mergeTwoLists(struct node* list1, struct node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    if (list1->val <= list2->val){
        list1->next =  mergeTwoLists(list1->next, list2);
        return list1;
    } else {
        list2->next =  mergeTwoLists(list1, list2->next);
        return list2;
    }

    return list1;
}

void print_linked_list(struct node *head) {
    while (head) {
        printf("%d\n", head->val);
        head = head->next;
    }
}

int main(void) {
    struct node *list1 = node_create(10);
    list1->next = node_create(20);
    list1->next->next = node_create(30);

    struct node *list2 = node_create(15);
    list2->next = node_create(25);
    list2->next->next = node_create(35);

    struct node *list3 = node_create(2);
    struct node *list4 = node_create(1);

    struct node *list5 = node_create(5);
    struct node *list6 = node_create(1);
    list6->next = node_create(2);
    list6->next->next = node_create(4);

    struct node *res = mergeTwoLists(list1, list2);
    struct node *res1 = mergeTwoLists(list3, list4);
    struct node *res2 = mergeTwoLists(list5, list6);

    print_linked_list(res);
    putchar('\n');
    print_linked_list(res1);
    putchar('\n');
    print_linked_list(res2);
}
