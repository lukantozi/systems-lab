#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

int main(void) {
    tree *t = tree_init(NULL, 6);
    assert(t != NULL);
    assert(t->value == 6);
    assert(t->parent == NULL);

    t->left = tree_init(t, 2);
    assert(t->left != NULL);
    assert(t->left->value == 2);
    assert(t->left->parent == t);

    t->right = tree_init(t, 8);
    assert(t->right != NULL);
    assert(t->right->value == 8);
    assert(t->right->parent == t);

    t->right->left = tree_init(t->right, 7);
    assert(t->right->left != NULL);
    assert(t->right->left->value == 7);
    assert(t->right->left->parent == t->right);

    t->right->right = tree_init(t->right, 9);
    assert(t->right->right != NULL);
    assert(t->right->right->value == 9);
    assert(t->right->right->parent == t->right);

    tree *fnd = tree_search(t, 7);
    assert(fnd != NULL);
    assert(fnd->value == 7);

    fnd = tree_search(t, 9);
    assert(fnd != NULL);
    assert(fnd->value == 9);

    fnd = tree_search(t, 8);
    assert(fnd != NULL);
    assert(fnd->value == 8);

    fnd = tree_search(t, 2);
    assert(fnd != NULL);
    assert(fnd->value == 2);

    fnd = tree_search(t, 10);
    assert(fnd == NULL);
    fnd = tree_search(NULL, 15);
    assert(fnd == NULL);

    tree_walk(t);
    assert(t->value == 6);
    assert(tree_insert(&t, t->parent, 3) == 1);
    assert(tree_insert(&t, t->parent, 1) == 1);

    fnd = tree_search(t, 3);
    assert(fnd != NULL);
    assert(fnd->value == 3);
    assert(t->left->right->value == 3);
    assert(t->left->right->parent == t->left);

    fnd = tree_search(t, 1);
    assert(fnd != NULL);
    assert(fnd->value == 1);
    assert(t->left->left->value == 1);
    assert(t->left->left->parent == t->left);

    assert(tree_insert(&t, t->parent, 1) == 1);
    fnd = tree_search(t, 1);
    assert(fnd != NULL);
    assert(fnd->value == 1);
    assert(t->left->left->left->value == 1);
    assert(t->left->left->left->parent == t->left->left);

    putchar('\n');
    tree_walk(t);

    tree *ret, *tmp;
    tmp = t;
    t = tree_remove(t, 5);
    assert(t == tmp);
    t = tree_remove(t, 1);
    ret = tree_search(t, 1);
    assert(ret != NULL);
    assert(ret->value == 1);
    t = tree_remove(t, 1);
    ret = tree_search(t, 1);
    assert(ret == NULL);
    ret = tree_search(t, 1);
    assert(ret == NULL);
    ret = tree_search(t, 8);
    assert(ret != NULL);
    assert(ret->value == 8);
    t = tree_remove(t, 8);
    ret = tree_search(t, 8);
    assert(ret == NULL);

    putchar('\n');
    tree_walk(t);

    assert(t->left->value == 2);
    assert(t->left->right->value == 3);
    assert(t->left->parent == t);
    assert(t->right->value == 9);
    assert(t->right->left->parent == t->right);
    assert(t->parent == NULL);

    t = tree_remove(t, 6);
    assert(t->value == 7);
    putchar('\n');
    tree_walk(t);

    tree *t1 = tree_init(NULL, 5);
    t1 = tree_remove(t1, 5);
    assert(t1 == NULL);

    tree *t2 = tree_init(NULL, 4);
    assert(tree_insert(&t2, t2->parent, 6) == 1);
    t2 = tree_remove(t2, 4);
    assert(t2->parent == NULL);

    tree *t3 = tree_init(NULL, 3);
    assert(tree_insert(&t3, t3->parent, 5) == 1);
    assert(tree_insert(&t3, t3->parent, 8) == 1);
    t3 = tree_remove(t3, 3);
    assert(t3->parent == NULL);
    ret = tree_search(t3, 5);
    assert(ret != NULL);
    ret = tree_search(t3, 8);
    assert(ret != NULL);

    assert(tree_free(t) == 1);
    assert(tree_free(t1) == 1);
    assert(tree_free(t2) == 1);
    assert(tree_free(t3) == 1);

    return 0;
}
