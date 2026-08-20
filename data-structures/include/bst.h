#ifndef BST_H
#define BST_H

typedef struct tree tree;

struct tree {
    int value;
    tree *parent;
    tree *left;
    tree *right;
};

tree *tree_init(tree *, int);
tree *tree_search(tree *, int);
void tree_walk(tree *);
int tree_insert(tree **, tree *, int);
tree *tree_remove(tree *, int);
int tree_free(tree *);

#endif
