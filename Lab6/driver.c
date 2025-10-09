#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main(void)
{
    string s1 = screate();
    scopy(s1, "Hello");
    string s2 = screate();
    scopy(s2, "World");

    printf("Compare s1 and s2: %d\n", scmp(s1, s2));

    string s3 = scat(s1, s2);
    printf("Concatenation: ");
    printString(s3);
    printf("\n");

    string upper = sToUpper(s1);
    string lower = sToLower(s1);
    printf("Upper: ");
    printString(upper);
    printf("\n");
    printf("Lower: ");
    printString(lower);
    printf("\n");

    free(s1);
    free(s2);
    free(s3);
    free(upper);
    free(lower);

    return 0;
}