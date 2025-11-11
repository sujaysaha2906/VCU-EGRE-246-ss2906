#ifndef BST_H
#define BST_H

typedef struct BSTNode {
    int key;
    struct BSTNode *left, *right;
} BSTNode;

BSTNode* bst_insert(BSTNode *root, int key);
BSTNode* bst_search(BSTNode *root, int key);      // returns pointer to node or NULL
BSTNode* bst_delete(BSTNode *root, int key);      // returns (possibly new) root
void bst_inorder(BSTNode *root);
void bst_preorder(BSTNode *root);
void bst_postorder(BSTNode *root);
void bst_free(BSTNode *root);

#endif