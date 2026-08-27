#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // for strcpy, strlen
#include <ctype.h>   // for isspace

#define TEXT_LENGTH 250
#define MAX_DB_SIZE 1000
#define MAX_DESCRIPTION_SIZE 160

// Structure definition for a widget
typedef struct wType {
    int id;        // widget id number
    int num;       // number in stock
    float cost;    // our unit cost
    char *des;     // description of item
} widget;

// Function prototypes
void initDB(widget *[], int);         // initialize db to NULL
int count(widget *[], int);           // return # of items in db
widget *newItem(int, int, float, char *); // create new widget
void printItem(widget *);             // print single widget
void printDB(widget*[], int);         // print all widgets

///////////////////////////////////////
int main(void) {
    widget *db[MAX_DB_SIZE]; // database = array of pointers
    int total;

    initDB(db, MAX_DB_SIZE); 
    printf("# items in database: %d\n", count(db, MAX_DB_SIZE));

    printf("enter how many items? ");
    scanf("%d", &total);

    if (total <= 0) exit(EXIT_SUCCESS);

    int id, num;
    float cost;
    char des[MAX_DESCRIPTION_SIZE], ch;
    des[0] = '\0';

    for (int i = 0; i < total; i++) {
        printf("Item #%d\n", i + 1);
        printf(" stock number: ");
        scanf("%d", &id);
        printf(" # in stock: ");
        scanf("%d", &num);
        printf(" unit cost: ");
        scanf("%f", &cost);

        printf(" description: ");
        while (isspace(ch = getchar()));  // skip whitespace/newlines
        ungetc(ch, stdin);
        scanf("%[^\n]", des);  // read full line until newline

        db[i] = newItem(id, num, cost, des); // create and store widget
    }

    printf("\nDatabase contents:\n");
    printDB(db, total);

    return 0;
}

///////////////////////////////////////
// Function Implementations

// 1. Initialize database (set all cells to NULL)
void initDB(widget *list[], int n) {
    if (n < 1) return;
    for (int i = 0; i < n; i++)
        list[i] = NULL;
}

// 2. Count number of non-NULL items in db
int count(widget *list[], int n) {
    if (n <= 0) return 0;
    int c = 0;
    for (int i = 0; i < n; i++)
        if (list[i] != NULL) c++;
    return c;
}

// 3. Create a new widget and return pointer
widget *newItem(int new_id, int new_num, float new_cost, char *new_des) {
    widget *tmp = malloc(sizeof(widget)); // allocate memory
    tmp->id = new_id;
    tmp->num = new_num;
    tmp->cost = new_cost;

    tmp->des = malloc(strlen(new_des) + 1); // allocate memory for description
    strcpy(tmp->des, new_des); // copy description into struct

    return tmp;
}

// 4. Print a single widget
void printItem(widget *item) {
    printf("stock number: %d\n", item->id);
    printf("in stock: %d\n", item->num);
    printf("unit cost: %.2f\n", item->cost);
    printf("description: %s\n", item->des);
    printf("-----------------------------\n");
}

// 5. Print the entire database
void printDB(widget *db[], int size) {
    int c = count(db, size);
    if (c <= 0) {
        printf("<database empty>\n");
        return;
    }
    
    for (int i = 0; i < c; i++) {
        printf("Item: %d\n", i+1);
        printItem(db[i]);
    }
}