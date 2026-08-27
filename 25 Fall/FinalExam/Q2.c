#include <stdio.h>

// my answer
// void swap(int *a, int *b) {
//     if (a == b) return;
//     *a ^= *b;
//     *b ^= *a;
//     *a ^= *b;
// }

// student's answer
void swap(int *a, int *b) {
    // a = a + b;
    // b = a - b;
    // a = a - b;
    // printf("x = %d, y = %d\n", a, b);
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main() {
    int x = 5, y = 9;
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}