#ifndef STRING_H
#define STRING_H

#include <stdio.h>

#define MAX_STRING_SIZE 128

typedef struct stringType *string;

struct stringType
{
    int length;
    char data[MAX_STRING_SIZE];
};

/* prototypes */
string screate();
void scopy(string s, char *cstr);
int slen(string s);
void printString(string s);

/* NEW ROUTINES */
int scmp(string s1, string s2);       /* like strcmp */
string scat(string dest, string src); /* like strcat, returns copy of dest */
string sToUpper(string s);            /* returns NEW string with chars uppercased */
string sToLower(string s);            /* returns NEW string with chars lowercased */

#endif /* STRING_H */