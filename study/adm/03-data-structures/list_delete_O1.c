#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct list {
    int value;
    struct list *next;
} list;

list *list_search(list *l, int x) {
    if (l == NULL)
        return NULL;

    if (l->value == x)
        return l;
    else
        return list_search(l->next, x);
}

int list_insert(list **l, int x) {
    if (*l == NULL)
        return -1;

    list *p = malloc(sizeof(list));
    if (p == NULL)
        return -1;

    p->value = x;
    p->next = *l;
    *l = p;

    return 1;
}

int list_delete(list *x) {
    if (x == NULL || x->next == NULL)
        return -1;

    list *p = x->next;

    x->value = p->value;
    x->next = p->next;
    free(p);

    return 1;
}

int list_show(list *head) {
    if (head == NULL)
        return -1;

    list *tmp;
    while (head) {
        tmp = head->next;
        printf(tmp ? "%d -> " : "%d\n", head->value);
        head = tmp;
    }

    return 1;
}

int list_free(list *head) {
    if (head == NULL)
        return -1;

    list *tmp;
    while (head != NULL) {
        tmp = head->next;
        free(head);
        head = tmp;
    }

    return 1;
}

int main(void) {
    list *l = malloc(sizeof(*l));
    assert(l != NULL);

    l->value = 25;
    l->next = NULL;
    assert(list_show(l) == 1);

    assert(list_insert(&l, 20) == 1);
    assert(list_show(l) == 1);
    assert(list_insert(&l, 15) == 1);
    assert(list_show(l) == 1);
    assert(list_insert(&l, 10) == 1);
    assert(list_show(l) == 1);
    assert(list_insert(&l, 5) == 1);
    assert(list_show(l) == 1);

    assert(list_delete(l->next) == 1);
    assert(l->value == 5);
    assert(l->next->value == 15);
    assert(l->next->next->value == 20);
    assert(l->next->next->next->value == 25);
    assert(list_show(l) == 1);

    assert(list_delete(l->next) == 1);
    assert(l->value == 5);
    assert(l->next->value == 20);
    assert(l->next->next->value == 25);
    assert(list_show(l) == 1);

    list *last = l;
    while (last->next != NULL)
        last = last->next;

    assert(last->value == 25);
    assert(last->next == NULL);
    assert(list_delete(last) == -1);
    assert(last->value == 25);
    assert(last->next == NULL);

    list *target = list_search(l, 20);
    assert(target != NULL);
    assert(list_delete(target) == 1);
    assert(l->value == 5);
    assert(l->next->value == 25);
    assert(list_show(l) == 1);

    assert(list_free(l) == 1);
}
