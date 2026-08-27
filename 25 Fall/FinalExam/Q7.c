#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Define the stack structure
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return (s->top < 0);
}

int isFull(Stack *s) {
    return (s->top >= MAX - 1);
}

// Push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

// Pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

// Function to swap two variables using the stack
// My answer
// void swapWithStack(Stack *s, int *a, int *b) {
//     push(s, *a);
//     push(s, *b);

//     *a = pop(s);   // old *b
//     *b = pop(s);   // old *a
// }

// Student's answer
void swapWithStack(Stack *s, int *a, int *b) {
    push(s, a);
    push(s, b);

    a = pop(s);   // old *b
    b = pop(s);   // old *a
}

int main(void) {
    Stack s;
    initStack(&s);

    int x = 10, y = 25;

    printf("Before swap: x=%d, y=%d\n", x, y);
    swapWithStack(&s, &x, &y);
    printf("After swap : x=%d, y=%d\n", x, y);

    return 0;
}