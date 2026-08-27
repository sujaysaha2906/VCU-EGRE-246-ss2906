#ifndef DY_STACK_H
#define DY_STACK_H

#include <stdbool.h>

typedef struct Stack {
    int *data;      // dynamic array
    int top;        // index of last element
    int capacity;   // current allocated size
} *stack;

// function prototypes
stack createStack();
void push(stack s, int x);
void pop(stack s);
void printStack(stack s);
int get(stack s, int p);
bool put(stack s, int x, int p);

#endif