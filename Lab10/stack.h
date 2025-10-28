#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX 100

typedef struct Stack {
    int data[MAX];
    int top;
} *stack;

// function prototypes
stack createStack();
void push(stack s, int x);
void pop(stack s);
void printStack(stack s);
int get(stack s, int p);
bool put(stack s, int x, int p);

#endif