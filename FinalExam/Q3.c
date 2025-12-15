#define MAX 100
#include <stdio.h>

typedef struct {
    char data[MAX];
    int size;
} *string;

void scopy(string s1, string s2) {   // copy s2 to s1
    int n = s2->size;
    if (n >= MAX) n = MAX - 1;       // leave room for '\0'

    for (int i = 0; i < n; i++) {
        s1->data[i] = s2->data[i];
    }

    s1->data[n] = '\0';
    s1->size = n;
}

int main() {
    struct {
        char data[MAX];
        int size;
    } str1, str2;

    // Initialize str2
    const char *text = "Hello, World!";
    int i = 0;
    while (text[i] != '\0' && i < MAX - 1) {
        str2.data[i] = text[i];
        i++;
    }
    str2.data[i] = '\0';
    str2.size = i;

    // Copy str2 to str1
    scopy(&str1, &str2);

    // Print str1
    printf("str1 data: %s\n", str1.data);
    printf("str1 size: %d\n", str1.size);

    return 0;
}