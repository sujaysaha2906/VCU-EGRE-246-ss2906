#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 128

struct listType {
    int data[MAX_SIZE];
    int size; // current number of items in list
};

typedef struct listType *alist;
void insertAtFront(alist list,int item);

// Function to create an empty list
alist createList() {
    return NULL;
}

void insertAtFront(alist list, int item) {
    int i;
    if (list->size=MAX_SIZE) return;
    for (i=list->size; i>0;i--)
        list->data [i]=list->data[i-1];
    list->data[0]=item;
    list->size++;
}

int main() {

    // Create an empty list
    alist l = createList();
    
    // Print the empty list
    printf("Empty list: ");
    // printList(l);
    printf("\n");
    
    // Add elements to the list
    insertAtFront(l, 2);
    insertAtFront(l, 4);
    insertAtFront(l, 6);

    // Print the list with elements
    printf("After adding 2, 4, 6: ");
    // printList(l);
    printf("\n");

    return 0;
}