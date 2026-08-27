#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define CHUNK 10
#define DEBUG true

typedef struct {
    int *data;
    int listSize; // current number of cells in array
    int count; // current number of items in list
} intList;

void addItem(intList*,int);
void printList(intList*);

int main(void) { 

    intList *l = malloc(sizeof(intList));
    l->data = NULL;
    l->count = l->listSize = 0;
    for (int i=1; i <= 112; i++)
        addItem(l,i*2);
    printList(l); printf("\n");
    return 0;
}

void addItem(intList *l, int item) {
    // Step 1: If no more room, allocate more
    if (l->count == l->listSize) {
        // allocate new array with CHUNK more space
        int *temp = malloc((l->listSize += CHUNK) * sizeof(int));
        if (temp == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(1);
        }
        
        // copy old data to new array if it exists
        for (int i = 0; i < l->count; i++) {
            temp[i] = l->data[i];
        }
        
        // store old pointer and update to new array
        int *old = l->data;
        l->data = temp;
        
        // free old array if not NULL
        if (old != NULL) {
            free(old);
        }
    }
    
    // Step 2: Add the new item
    l->data[l->count] = item;
    l->count++;
}

void printList(intList *l) {
    for (int i=0; i<l->count; i++) {
        printf("%d ",l->data[i]);
    }
}