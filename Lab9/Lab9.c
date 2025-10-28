#include <stdio.h>
#include <stdlib.h>

struct dlnode {
    int data;
    struct dlnode *prev;
    struct dlnode *next;
};

typedef struct dlnode *dllist;

dllist createDList(); // returns empty dllist
void printDList(dllist); // prints dllist
dllist addAtEnd(const dllist l, int n); // adds n to end of l
dllist removeAtFront(dllist);
void revPrintDList(dllist); // prints list in reverse order

int main(void) {
    dllist dl = createDList();
    
    printf("newly created list: "); 
    printDList(dl); 
    printf("\n");
    
    dl = addAtEnd(dl, 2);
    dl = addAtEnd(dl, 4);
    dl = addAtEnd(dl, 6);
    printf("list: "); 
    printDList(dl); 
    printf("\n");
    
    printf("list reversed: "); 
    revPrintDList(dl); 
    printf("\n");
    
    dl = removeAtFront(dl);
    printf("after remove front item: ");
    printDList(dl); 
    printf("\n");
    
    dl = removeAtFront(dl); 
    dl = removeAtFront(dl);
    dl = removeAtFront(dl); 
    dl = removeAtFront(dl);
    printf("after removing all items: "); 
    printDList(dl); 
    printf("\n");
    
    return 0;
}

dllist createDList() { 
    return NULL; 
}

void printDList(dllist dl) {
    if (dl == NULL) {
        printf("NULL");
    } else {
        struct dlnode *current = dl;
        printf("[");
        while (current != NULL) {
            printf("%d", current->data);
            if (current->next != NULL) {
                printf(", ");
            }
            current = current->next;
        }
        printf("]");
    }
}

dllist addAtEnd(const dllist l, int n) {
    // Create (malloc) a new node
    struct dlnode *newNode = (struct dlnode *)malloc(sizeof(struct dlnode));
    
    // Initialize the fields of this node
    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    // If list is empty
    if (l == NULL) {
        return newNode;
    } else {
        // Traverse to the end of the list
        struct dlnode *current = l;
        while (current->next != NULL) {
            current = current->next;
        }
        
        // Add the new node to the end
        current->next = newNode;
        newNode->prev = current;  // Set the prev pointer of new node
        
        // Return the original list (head unchanged)
        return l;
    }
}

dllist removeAtFront(dllist dl) {
    // If list is not empty
    if (dl != NULL) {
        // Set a local variable ptr to point to first node
        struct dlnode *ptr = dl;
        
        // Set dl to point to the next node
        dl = dl->next;
        
        // If the new head exists, set its prev pointer to NULL
        if (dl != NULL) {
            dl->prev = NULL;
        }
        
        // Free the first node
        free(ptr);
    }
    
    
    // Return the updated list
    return dl;
}

void revPrintDList(dllist dl) {
    if (dl == NULL) {
        printf("NULL");
    } else {
        // First, traverse to the end of the list
        struct dlnode *current = dl;
        while (current->next != NULL) {
            current = current->next;
        }
        
        // Now traverse backwards using prev pointers
        printf("[");
        while (current != NULL) {
            printf("%d", current->data);
            if (current->prev != NULL) {
                printf(", ");
            }
            current = current->prev;
        }
        printf("]");
    }
}