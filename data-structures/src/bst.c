#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

#define BST_NULL_ERROR(prog, arg, ret)                   \
    do {                                                 \
        fprintf(stderr, "[ERROR] tree_%s: %s is NULL\n", \
                prog, arg);                              \
        return ret;                                      \
    } while (0)

tree *tree_init(tree *par, int val) {
    tree *n = malloc(sizeof(*n));
    if (n == NULL)
        BST_NULL_ERROR("init", "n", NULL);

    n->value = val;
    n->left = n->right = NULL;
    n->parent = par;
    return n;
}

tree *tree_search(tree *t, int val) {
    if (t == NULL)
        return NULL;

    if (t->value == val)
        return t;

    if (val < t->value)
        return tree_search(t->left, val);
    else 
        return tree_search(t->right, val);
}

void tree_walk(tree *t) {
    if (t != NULL) {
        tree_walk(t->left);
        printf("node: %d\n", t->value);
        tree_walk(t->right);
    }
}

int tree_insert(tree **tree_ins, tree *tree_par, int val) {
    tree *p;
    if (tree_ins == NULL)
        BST_NULL_ERROR("insert", "tree_inst", -1);

    if (*tree_ins == NULL) {
        p = tree_init(tree_par, val);
        if (p == NULL)
            return -1;
        *tree_ins = p;
        return 1;
    }

    if (val > (*tree_ins)->value)
        return tree_insert(&(*tree_ins)->right, *tree_ins, val);
    else
        return tree_insert(&(*tree_ins)->left, *tree_ins, val);
}

tree *tree_remove(tree *t, int val) {
    if (t == NULL)
        return t;

    if (val > t->value) {
        t->right = tree_remove(t->right, val);
    } else if (val < t->value) {
        t->left = tree_remove(t->left, val);
    } else {
        if (t->left == NULL) { 
            tree *tmp = t->right;
            if (tmp != NULL)
                tmp->parent = t->parent;
            free(t);
            return tmp;
        }
        if (t->right == NULL) {
            tree *tmp = t->left;
            if (tmp != NULL)
                tmp->parent = t->parent;
            free(t);
            return tmp;
        }

        tree *curr = t;
        curr = curr->right;
        while (curr != NULL && curr->left != NULL)
            curr = curr->left;

        t->value = curr->value;
        t->right = tree_remove(t->right, curr->value);
    }

    return t;
}

int tree_free(tree *root) {
    if (root == NULL)
        return 1;

    tree_free(root->left);
    tree_free(root->right);
    free(root);
    return 1;
}
