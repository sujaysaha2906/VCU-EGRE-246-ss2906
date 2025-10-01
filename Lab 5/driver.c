#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(void)
{
    string s1 = screate();
    if (!s1)
    {
        perror("screate");
        return 1;
    }

    scopy(s1, "hi mom");
    printf("s1 length = %d\n", slen(s1));
    printString(s1);
    putchar('\n');

    /* empty string test */
    string s2 = screate();
    scopy(s2, "");
    printf("s2 length = %d\n", slen(s2));
    printString(s2);
    putchar('\n');

    /* longer string test */
    scopy(s2, "This is a longer test string to check boundaries.");
    printf("s2 length = %d\n", slen(s2));
    printString(s2);
    putchar('\n');

    /* overflow test: create a C string longer than MAX_STRING_SIZE */
    char big[MAX_STRING_SIZE + 50];
    for (int i = 0; i < (int)(sizeof(big) - 1); ++i)
        big[i] = 'A' + (i % 26);
    big[sizeof(big) - 1] = '\0';

    string s3 = screate();
    scopy(s3, big);
    printf("s3 length = %d (should be <= %d)\n", slen(s3), MAX_STRING_SIZE);
    printString(s3);
    putchar('\n');

    /* cleanup */
    free(s1);
    free(s2);
    free(s3);

    return 0;
}