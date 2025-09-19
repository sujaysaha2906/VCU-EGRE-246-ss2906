#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for strcpy
#include <ctype.h>  // for isspace
int count_Size = 0;
#define TEXT_LENGTH 250
#define MAX_DESCRIPTION_SIZE 160
int count_array_size = 0;
#define EXPANSION_SIZE 2

typedef struct wType
{
    int id;     // widget id number
    int num;    // number in stock
    float cost; // our unit cost
    char *des;  // description of item
} widget;

int count(widget *, int);                 // returns count of actual items in db
widget *newItem(int, int, float, char *); // creates and returns a new db item
void printItem(widget *);                 // prints a single db item
void printDB(widget *, int);              // prints all db items
widget *insert(widget *, widget *);

///////////////////////////////////////

int main(void)
{
    int total;
    widget *db = NULL;
    printf("# items in database: %d\n", count(db, count_Size));
    printf("enter how many items? ");
    scanf("%d", &total);
    if (total <= 0)
        exit(EXIT_SUCCESS);

    int id, num;
    float cost;
    char des[MAX_DESCRIPTION_SIZE], ch;
    des[0] = '\0';
    for (int i = 0; i < total; i++)
    {
        printf("Item #%d\n", i + 1);
        printf("  stock number: ");
        scanf("%d", &id);
        printf("  # in stock: ");
        scanf("%d", &num);
        printf("  unit cost: ");
        scanf("%f", &cost);
        printf("  description: ");
        while (isspace(ch = getchar()))
            ; // see notes in handout on this
        ungetc(ch, stdin);
        scanf("%[^\n]", des);
        db = insert(db, newItem(id, num, cost, des));
    }

    printf("\nDatabase contents:\n");
    printDB(db, total);

    return 0;
}

widget *insert(widget *list, widget *item)
{
    widget *l = list;
    if (count_Size >= count_array_size)
    {

        l = (widget *)malloc((count_array_size = count_array_size + EXPANSION_SIZE) * sizeof(widget));
        if (list != NULL)
        {
            for (int i = 0; i < count_Size; i++)
            {
                l[i] = list[i];
            }
            free(list);
        }
    }
    l[count_Size++] = *item;

    return l;
}

widget *newItem(int new_id, int new_num, float new_cost, char *new_des)
{

    widget *tmp = malloc(sizeof(widget));
    tmp->id = new_id;
    tmp->num = new_num;
    tmp->cost = new_cost;
    tmp->des = malloc(strlen(new_des) + 1);
    strcpy(tmp->des, new_des);
    return tmp;
}

void printItem(widget *item)
{
    printf("stock number: %d\n", item->id);
    printf("# in stock: %d\n", item->num);
    printf("Unit cost: %f\n", item->cost);
    printf("description: %s\n", item->des);
}

int count(widget *list, int n)
{
    return count_Size;
}

void printDB(widget *db, int size)
{ // prints all db items
    int c = count_Size;
    printf("test: %d\n", count_Size);
    if (c <= 0)
    {
        printf("<database empty>\n");
        return;
    }
    for (int i = 0; i < c; i++)
    {
        printf("Item #%d\n", i + 1);
        printItem(&db[i]);
    }
}