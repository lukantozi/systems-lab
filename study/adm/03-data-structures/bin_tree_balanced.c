#include <assert.h>
#include <stdio.h>

typedef struct tree {
    int value;
    struct tree *left;
    struct tree *right;
} tree;

int is_balanced(tree *t) {
    if (t != NULL) {
        if (t->left == NULL && t->right == NULL)
            return 1;

        int left_depth = is_balanced(t->left);
        int right_depth = is_balanced(t->right);
        if (left_depth == -1 || right_depth == -1)
            return -1;

        int diff = left_depth - right_depth;
        if (diff >= -1 && diff <= 1)
            return 1 + (left_depth >= right_depth ? left_depth : right_depth);
        else
            return -1;
    }
    return 0;
}

int bin_tree_balanced(tree *t) {
    return is_balanced(t) != -1;
}

int main(void) {
    tree *t = &(tree) {.value = 3};
    t->left = &(tree) {.value = 9};
    t->left->left = NULL;
    t->left->right = NULL;
    t->right = &(tree) {.value = 20};
    t->right->left = &(tree) {.value = 15};
    t->right->right = &(tree) {.value = 7};
    t->right->left->right = NULL;
    t->right->left->left = NULL;
    t->right->right->right = NULL;
    t->right->right->left = NULL;
    int x = bin_tree_balanced(t);
    printf("%d\n", x);
    assert(x == 1);

    tree *t1 = &(tree) {.value = 1};
    t1->right = &(tree) {.value = 2};
    t1->right->left = NULL;
    t1->right->right = NULL;
    t1->left = &(tree) {.value = 2};
    t1->left->right = &(tree) {.value = 3};
    t1->left->left = &(tree) {.value = 3};
    t1->left->right->right = NULL;
    t1->left->left->left = &(tree) {.value = 4};
    t1->left->left->right = &(tree) {.value = 4};
    t1->left->left->left->left = NULL;
    t1->left->left->left->right = NULL;
    t1->left->left->right->left = NULL;
    t1->left->left->right->right = NULL;
    x = bin_tree_balanced(t1);
    printf("%d\n", x);
    assert(x == 0);

    tree *t2 = NULL;
    x = bin_tree_balanced(t2);
    printf("%d\n", x);
    assert(x == 1);

    tree *t3 = &(tree) {.value = 1};
    t3->left = &(tree) {.value = 2};
    t3->left->left = &(tree) {.value = 3};
    t3->left->left->left = &(tree) {.value = 4};

    t3->right = &(tree) {.value = 2};
    t3->right->right = &(tree) {.value = 3};
    t3->right->right->right = &(tree) {.value = 4};
    x = bin_tree_balanced(t3);
    printf("%d\n", x);
    assert(x == 0);

    tree *t4 = &(tree) {.value = 1};
    t4->left = &(tree) {.value = 2};
    x = bin_tree_balanced(t4);
    printf("%d\n", x);
    assert(x == 1);
}
