// bst_main.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

#define MAXN 100
#define NUM_SEARCHES 10
#define NUM_DELETES 3

int main(void) {
    FILE *fp = fopen("lab11.dat", "r");
    if (!fp) {
        perror("Error opening lab11.dat");
        return 1;
    }

    BSTNode *root = NULL;
    int vals[MAXN], n = 0, x;

    while (n < MAXN && fscanf(fp, "%d", &x) == 1) {
        if (x == -1) break;
        if (x <= 0) { fprintf(stderr, "Non-positive value ignored: %d\n", x); continue; }
        vals[n++] = x;
        root = bst_insert(root, x);
    }
    fclose(fp);

    if (n == 0) {
        fprintf(stderr, "No values read (before -1).\n");
        return 1;
    }

    printf("BST built from %d values.\n", n);
    printf("Inorder   (sorted): "); bst_inorder(root);   printf("\n");
    printf("Preorder         : "); bst_preorder(root); printf("\n");
    printf("Postorder        : "); bst_postorder(root);printf("\n");

    srand((unsigned)time(NULL));

    // Random searches
    int minv = vals[0], maxv = vals[0];
    for (int i = 1; i < n; ++i) {
        if (vals[i] < minv) minv = vals[i];
        if (vals[i] > maxv) maxv = vals[i];
    }
    int lo = (minv > 1 ? minv - (minv/3 + 1) : 1);
    int hi = maxv + (maxv/3 + 10);

    printf("\nRandom BST searches:\n");
    for (int i = 0; i < NUM_SEARCHES; ++i) {
        int key = lo + rand() % (hi - lo + 1);
        BSTNode *found = bst_search(root, key);
        printf("Query %2d: key=%d -> %s\n", i+1, key, (found ? "FOUND" : "not found"));
    }

    // Demonstrate deletions (delete up to first NUM_DELETES original values)
    printf("\nDeleting first %d inserted keys (or fewer if n < %d):\n", NUM_DELETES, NUM_DELETES);
    for (int i = 0; i < NUM_DELETES && i < n; ++i) {
        printf("Delete %d\n", vals[i]);
        root = bst_delete(root, vals[i]);
        printf("Inorder after delete: "); bst_inorder(root); printf("\n");
    }

    bst_free(root);
    return 0;
}