#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 29          // M: size of hash table (prime is nice)
#define NUM_INSERT 120         // > 100 keys to insert
#define NUM_SEARCH 15          // > 10 searches

/* ------------------ Node definition for separate chaining ------------------ */

typedef struct Node {
    int key;
    struct Node *next;
} Node;

/* ------------------------------- Hash table -------------------------------- */

Node *hashTable[TABLE_SIZE];

/* Hash function: h(x) = x % M */
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

/* Initialize hash table buckets to NULL */
void initHashTable(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

/* Insert a key into the hash table (no duplicates) */
void insertKey(int key) {
    if (key <= 0) {
        // we only store positive integers, ignore others
        return;
    }

    int index = hashFunction(key);
    Node *head = hashTable[index];

    // Check if key already exists
    Node *curr = head;
    while (curr != NULL) {
        if (curr->key == key) {
            // Key already in table; do not insert duplicate
            return;
        }
        curr = curr->next;
    }

    // Insert new node at the beginning of the list
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->next = head;
    hashTable[index] = newNode;
}

/* Search for a key in the hash table; return 1 if found, 0 otherwise */
int searchKey(int key) {
    if (key <= 0) return 0;

    int index = hashFunction(key);
    Node *curr = hashTable[index];

    while (curr != NULL) {
        if (curr->key == key) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

/* Delete a key from the hash table; return 1 if deleted, 0 if not found */
int deleteKey(int key) {
    if (key <= 0) return 0;

    int index = hashFunction(key);
    Node *curr = hashTable[index];
    Node *prev = NULL;

    while (curr != NULL) {
        if (curr->key == key) {
            // Unlink the node
            if (prev == NULL) {
                // Node is at head
                hashTable[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }
    return 0;  // not found
}

/* Print the entire hash table (for debugging / demonstration) */
void printHashTable(void) {
    printf("Hash table contents:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Bucket %2d: ", i);
        Node *curr = hashTable[i];
        if (!curr) {
            printf("(empty)");
        } else {
            while (curr != NULL) {
                printf("%d -> ", curr->key);
                curr = curr->next;
            }
            printf("NULL");
        }
        printf("\n");
    }
}

/* Free all nodes in the hash table */
void freeHashTable(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *curr = hashTable[i];
        while (curr != NULL) {
            Node *temp = curr;
            curr = curr->next;
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

/* ---------------------------------- main ----------------------------------- */

int main(void) {
    srand((unsigned int)time(NULL));

    initHashTable();

    int keys[NUM_INSERT];

    /* 1) Insert more than 100 random positive keys */
    printf("Inserting %d random keys into the hash table...\n", NUM_INSERT);
    for (int i = 0; i < NUM_INSERT; i++) {
        // Generate positive integers (1 to 1000)
        int k = rand() % 1000 + 1;
        keys[i] = k;
        insertKey(k);
    }

    printHashTable();
    printf("\n");

    /* 2) Randomly search more than 10 keys from the hash table */
    printf("Searching %d keys in the hash table...\n", NUM_SEARCH);
    for (int i = 0; i < NUM_SEARCH; i++) {
        int keyToSearch;
        if (i < NUM_SEARCH / 2) {
            // First half: choose keys that were definitely inserted
            int idx = rand() % NUM_INSERT;
            keyToSearch = keys[idx];
        } else {
            // Second half: random keys, may or may not exist
            keyToSearch = rand() % 1000 + 1;
        }

        int found = searchKey(keyToSearch);
        printf("Search for %4d: %s\n", keyToSearch, found ? "FOUND" : "NOT FOUND");
    }
    printf("\n");

    /* 3) Test delete function */
    printf("Testing delete function on some keys...\n");
    for (int i = 0; i < 10; i++) {  // delete first 10 inserted keys
        int k = keys[i];
        int deleted = deleteKey(k);
        printf("Delete %4d: %s\n", k, deleted ? "DELETED" : "NOT FOUND");
    }
    printf("\n");

    // Verify that deleted keys are really gone
    printf("Verifying deleted keys...\n");
    for (int i = 0; i < 10; i++) {
        int k = keys[i];
        int found = searchKey(k);
        printf("Search after delete %4d: %s\n", k, found ? "STILL PRESENT (ERROR)" : "NOT FOUND (OK)");
    }
    printf("\n");

    // Show hash table after deletions
    printHashTable();

    /* 4) Clean up memory */
    freeHashTable();

    return 0;
}