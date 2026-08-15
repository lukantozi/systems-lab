#include <assert.h>
#include <stdio.h>

typedef struct tree {
    int value;
    struct tree *left;
    struct tree *right;
} tree;

int max_depth(tree *t) {
    int left_depth = 0;
    int right_depth = 0;
    if (t != NULL) {
        if (t->left == NULL && t->right == NULL)
            return 1;
        left_depth = max_depth(t->left);
        right_depth = max_depth(t->right);
        return 1 + (right_depth >= left_depth ? right_depth : left_depth);
    }
    return 0;
}

int main(void) {
    tree *t = &(tree) {.value = 3};
    t->left = &(tree) {.value = 9};
    t->left->left = NULL;
    t->left->right = NULL;
    t->right = &(tree) {.value = 20};
    t->right->left = &(tree) {.value = 15};
    t->right->right = &(tree) {.value = 7};
    t->right->left->left = NULL;
    t->right->left->right = NULL;

    int x = max_depth(t);
    printf("%d\n", x);
    assert(x == 3);

    tree *t1 = &(tree) {.value = 1};
    t1->left = NULL;
    t1->right = &(tree) {.value = 2};
    t1->right->left = NULL;
    t1->right->right = NULL;
    x = max_depth(t1);
    printf("%d\n", x);
    assert(x == 2);

    tree *t2 = NULL;
    x = max_depth(t2);
    printf("%d\n", x);
    assert(x == 0);

    tree *t3 = &(tree) {.value = 0};
    t3->left = NULL;
    t3->right = NULL;
    x = max_depth(t3);
    printf("%d\n", x);
    assert(x == 1);
}
