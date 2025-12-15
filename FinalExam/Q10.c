#include <stdio.h>
#include <stdlib.h>

struct node {
    int v;                 // data
    struct node *next;     // next
};

typedef struct node *PNode;

PNode InsertWithOrder(PNode head, int d) {
    PNode n = (PNode)malloc(sizeof(struct node));
    if (n == NULL) {
        printf("malloc failed\n");
        exit(1);
    }
    n->v = d;
    n->next = NULL;

    // insert at beginning
    if (head == NULL || d <= head->v) {
        n->next = head;
        return n;
    }

    // find insertion spot
    PNode cur = head;
    while (cur->next != NULL && cur->next->v < d) {
        cur = cur->next;
    }

    n->next = cur->next;
    cur->next = n;
    return head;
}

void printList(PNode head) {
    while (head != NULL) {
        printf("%d -> ", head->v);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(PNode head) {
    while (head != NULL) {
        PNode tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main(void) {
    PNode head = NULL;

    // build a sorted list by inserting values
    int vals[] = {15, 5, 20, 7, 7, 3, 18};
    int n = (int)(sizeof(vals) / sizeof(vals[0]));

    for (int i = 0; i < n; i++) {
        head = InsertWithOrder(head, vals[i]);
    }

    printf("Sorted list:\n");
    printList(head);

    freeList(head);
    return 0;
}
