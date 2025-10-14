#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *next;
};

// Define the list type as a pointer to a node
typedef struct node *llist;

// Function to create an empty list
llist createList() {
    return NULL;
}

// Function to print the list
void printList(llist l) {
    if (l == NULL) {
        printf("NULL");
    } else {
        struct node *current = l;
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

// Function to add a node at the end of the list
llist addAtEnd(const llist l, int n) {
    // Create (malloc) a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    
    // Initialize the fields of this node
    newNode->data = n;
    newNode->next = NULL;
    
    // If list is empty
    if (l == NULL) {
        return newNode;
    } else {
        // Traverse to the end of the list
        struct node *current = l;
        while (current->next != NULL) {
            current = current->next;
        }
        
        // Add the new node to the end
        current->next = newNode;
        
        // Return the original list (head unchanged)
        return l;
    }
}

// Function to remove the first item from the list
llist removeAtFront(llist l) {
    // If list is not empty
    if (l != NULL) {
        // Set a local variable ptr to point to first node
        struct node *ptr = l;
        
        // Set l to point to the next node
        l = l->next;
        
        // Free the first node
        free(ptr);
    }
    
    // Return the updated list
    return l;
}

// Function to get the size of the list
int getSize(llist l) {
    int size = 0;
    struct node *current = l;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

// Function to add an element at a specific position
llist add(llist l, int n, int pos) {
    // Get the size of the list
    int size = getSize(l);
    
    // If pos < 0, print warning and return unaltered list
    if (pos < 0) {
        printf("Warning: position %d is invalid (cannot be negative)\n", pos);
        return l;
    }
    
    // If pos >= size, add at end
    if (pos >= size) {
        return addAtEnd(l, n);
    }
    
    // If pos == 0, add at front (empty or non-empty list)
    if (pos == 0) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = n;
        newNode->next = l;
        return newNode;
    }
    
    // Otherwise, insert in the middle
    // Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = n;
    
    // Traverse to the node at position pos-1
    struct node *current = l;
    for (int i = 0; i < pos - 1; i++) {
        current = current->next;
    }
    
    // Insert the new node
    newNode->next = current->next;
    current->next = newNode;
    
    return l;
}

int main() {
    // Create an empty list
    llist l = createList();
    
    // Print the empty list
    printf("Empty list: ");
    printList(l);
    printf("\n\n");
    
    // Add elements to the list for testing
    l = addAtEnd(l, 2);
    l = addAtEnd(l, 4);
    l = addAtEnd(l, 6);
    
    printf("Starting list: ");
    printList(l);
    printf("\n\n");
    
    // Test 1: Add to an empty list
    printf("Test 1: Adding 10 to empty list at position 0\n");
    llist emptyList = createList();
    emptyList = add(emptyList, 10, 0);
    printList(emptyList);
    printf("\n\n");
    
    // Test 2: Add at position 0 (front of non-empty list)
    printf("Test 2: Adding 1 at position 0 (front)\n");
    printf("Before: ");
    printList(l);
    printf("\n");
    l = add(l, 1, 0);
    printf("After:  ");
    printList(l);
    printf("\n\n");
    
    // Test 3: Add in the middle
    printf("Test 3: Adding 3 at position 2 (middle)\n");
    printf("Before: ");
    printList(l);
    printf("\n");
    l = add(l, 3, 2);
    printf("After:  ");
    printList(l);
    printf("\n\n");
    
    // Test 4: Add at the end
    printf("Test 4: Adding 8 at position 7 (at end)\n");
    printf("Before: ");
    printList(l);
    printf("\n");
    l = add(l, 8, 7);
    printf("After:  ");
    printList(l);
    printf("\n\n");
    
    // Test 5: Add with position < 0 (warning case)
    printf("Test 5: Adding 99 at position -1 (negative position)\n");
    printf("Before: ");
    printList(l);
    printf("\n");
    l = add(l, 99, -1);
    printf("After:  ");
    printList(l);
    printf("\n\n");
    
    // Test 6: Add with position > size of list
    printf("Test 6: Adding 100 at position 50 (beyond size)\n");
    printf("Before: ");
    printList(l);
    printf("\n");
    l = add(l, 100, 50);
    printf("After:  ");
    printList(l);
    printf("\n\n");
    
    // Clean up memory
    while (l != NULL) {
        l = removeAtFront(l);
    }
    while (emptyList != NULL) {
        emptyList = removeAtFront(emptyList);
    }
    
    return 0;
}