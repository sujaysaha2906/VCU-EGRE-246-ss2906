#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

stack createStack() {
    stack s = (stack)malloc(sizeof(struct Stack));
    s->top = -1;
    return s;
}

void push(stack s, int x) {
    if (s->top == MAX - 1) return; // stack full
    s->data[++s->top] = x;
}

void pop(stack s) {
    if (s->top == -1) return; // stack empty
    s->top--;
}

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

int get(stack s, int p) {
    if (s->top == -1 || p < 0 || p > s->top)
        return INT_MIN;
    return s->data[p];
}

bool put(stack s, int x, int p) {
    if (p < 0 || s->top == MAX - 1) return false;

    // if p is greater than size, treat as push at the end
    if (p > s->top + 1) p = s->top + 1;

    for (int i = s->top; i >= p; i--) {
        s->data[i + 1] = s->data[i];
    }

    s->data[p] = x;
    s->top++;
    return true;
}