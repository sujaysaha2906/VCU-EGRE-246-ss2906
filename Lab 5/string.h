#ifndef STRING_H
#define STRING_H

#include <stdio.h>

#define MAX_STRING_SIZE 128 /* arbitrary */

typedef struct stringType *string;

struct stringType
{
    int length;                 /* current length (number of chars in data) */
    char data[MAX_STRING_SIZE]; /* storage for characters (no '\0' termination) */
};

/* prototypes */
string screate();                 /* returns a newly created string (malloc'd) */
void scopy(string s, char *cstr); /* copy null-terminated C string into s (do not copy '\0') */
int slen(string s);               /* return the length stored in the structure */
void printString(string s);       /* print the string (no newline) */

#endif /* STRING_H */