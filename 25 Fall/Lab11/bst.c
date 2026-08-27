// bst.c
#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

static BSTNode* new_node(int key) {
    BSTNode *n = (BSTNode*)malloc(sizeof(BSTNode));
    if (!n) { perror("malloc"); exit(1); }
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

BSTNode* bst_insert(BSTNode *root, int key) {
    if (!root) return new_node(key);
    if (key < root->key) root->left = bst_insert(root->left, key);
    else if (key > root->key) root->right = bst_insert(root->right, key);
    // duplicates ignored (keys are unique per spec)
    return root;
}

BSTNode* bst_search(BSTNode *root, int key) {
    while (root) {
        if (key == root->key) return root;
        root = (key < root->key) ? root->left : root->right;
    }
    return NULL;
}

static BSTNode* min_node(BSTNode *root) {
    while (root && root->left) root = root->left;
    return root;
}

BSTNode* bst_delete(BSTNode *root, int key) {
    if (!root) return NULL;
    if (key < root->key) {
        root->left = bst_delete(root->left, key);
    } else if (key > root->key) {
        root->right = bst_delete(root->right, key);
    } else {
        // found it
        if (!root->left) {
            BSTNode *r = root->right;
            free(root);
            return r;
        } else if (!root->right) {
            BSTNode *l = root->left;
            free(root);
            return l;
        } else {
            BSTNode *succ = min_node(root->right);
            root->key = succ->key;
            root->right = bst_delete(root->right, succ->key);
        }
    }
    return root;
}

void bst_inorder(BSTNode *root) {
    if (!root) return;
    bst_inorder(root->left);
    printf("%d ", root->key);
    bst_inorder(root->right);
}

void bst_preorder(BSTNode *root) {
    if (!root) return;
    printf("%d ", root->key);
    bst_preorder(root->left);
    bst_preorder(root->right);
}

void bst_postorder(BSTNode *root) {
    if (!root) return;
    bst_postorder(root->left);
    bst_postorder(root->right);
    printf("%d ", root->key);
}

void bst_free(BSTNode *root) {
    if (!root) return;
    bst_free(root->left);
    bst_free(root->right);
    free(root);
}