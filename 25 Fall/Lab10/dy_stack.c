#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dy_stack.h"

#define INITIAL_CAPACITY 4

// Create a new stack
stack createStack() {
    stack s = (stack)malloc(sizeof(struct Stack));
    s->data = (int*)malloc(sizeof(int) * INITIAL_CAPACITY);
    s->top = -1;
    s->capacity = INITIAL_CAPACITY;
    return s;
}

// Resize the dynamic array when needed
void resize(stack s) {
    s->capacity *= 2; // double the size
    s->data = (int*)realloc(s->data, s->capacity * sizeof(int));
}

// Push x onto the stack
void push(stack s, int x) {
    if (s->top + 1 == s->capacity) {
        resize(s);
    }
    s->data[++s->top] = x;
}

// Pop item from stack
void pop(stack s) {
    if (s->top == -1) return;
    s->top--;
}

// Print stack elements
void printStack(stack s) {
    if (s->top == -1) {
        printf("[]");
        return;
    }

    printf("[");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->data[i]);
        if (i < s->top) printf(", ");
    }
    printf("]");
}

// Get value at position p
int get(stack s, int p) {
    if (s->top == -1 || p < 0 || p > s->top)
        return INT_MIN;
    return s->data[p];
}

// Insert x at position p
bool put(stack s, int x, int p) {
    if (p < 0) return false;

    // If insertion at/beyond end, treat as push
    if (p > s->top + 1) p = s->top + 1;

    // Resize if necessary
    if (s->top + 1 == s->capacity) {
        resize(s);
    }

    // Shift elements to the right
    for (int i = s->top; i >= p; i--) {
        s->data[i + 1] = s->data[i];
    }

    s->data[p] = x;
    s->top++;

    return true;
}