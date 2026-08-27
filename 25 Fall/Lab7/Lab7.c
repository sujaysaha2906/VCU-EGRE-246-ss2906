#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node
{
    int data;
    struct node *next;
};

// Define the list type as a pointer to a node
typedef struct node *llist;

// Function to create an empty list
llist createList()
{
    return NULL;
}

// Function to print the list
void printList(llist l)
{
    if (l == NULL)
    {
        printf("NULL");
    }
    else
    {
        struct node *current = l;
        printf("[");
        while (current != NULL)
        {
            printf("%d", current->data);
            if (current->next != NULL)
            {
                printf(", ");
            }
            current = current->next;
        }
        printf("]");
    }
}

// Function to add a node at the end of the list
llist addAtEnd(const llist l, int n)
{
    // Create (malloc) a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    // Initialize the fields of this node
    newNode->data = n;
    newNode->next = NULL;

    // If list is empty
    if (l == NULL)
    {
        return newNode;
    }
    else
    {
        // Traverse to the end of the list
        llist current = l;
        while (current->next != NULL)
        {
            current = current->next;
        }

        // Add the new node to the end
        current->next = newNode;

        // Return the original list (head unchanged)
        return l;
    }
}

// Function to remove the first item from the list
llist removeAtFront(llist l)
{
    // If list is not empty
    if (l != NULL)
    {
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

int main()
{
    // Create an empty list
    llist l = createList();

    // Print the empty list
    printf("Empty list: ");
    printList(l);
    printf("\n");

    // Add elements to the list
    l = addAtEnd(l, 2);
    l = addAtEnd(l, 4);
    l = addAtEnd(l, 6);

    // Print the list with elements
    printf("After adding 2, 4, 6: ");
    printList(l);
    printf("\n");

    // Remove elements from the front
    l = removeAtFront(l);
    printf("After removing front: ");
    printList(l);
    printf("\n");

    l = removeAtFront(l);
    printf("After removing front again: ");
    printList(l);
    printf("\n");

    l = removeAtFront(l);
    printf("After removing front (empty): ");
    printList(l);
    printf("\n");

    // Test removing from empty list
    l = removeAtFront(l);
    printf("After removing from empty list: ");
    printList(l);
    printf("\n");

    return 0;
}