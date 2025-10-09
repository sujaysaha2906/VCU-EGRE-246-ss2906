#include "string.h"
#include <stdlib.h> /* malloc */

/* create a new string object (malloc) */
string screate()
{
    string s = (string)malloc(sizeof(struct stringType));
    if (s == NULL)
        return NULL;
    s->length = 0;
    /* do not write a terminating '\0' per lab spec */
    return s;
}

/* copy characters from a null-terminated C string into our string type.
   Do NOT copy the terminating '\0'; update length accordingly.
   If cstr is longer than MAX_STRING_SIZE, copy up to MAX_STRING_SIZE chars. */
void scopy(string s, char *cstr)
{
    if (s == NULL || cstr == NULL)
        return;
    int i = 0;
    while (cstr[i] != '\0' && i < MAX_STRING_SIZE)
    {
        s->data[i] = cstr[i];
        i++;
    }
    s->length = i;
    /* intentionally do not place '\0' in s->data */
}

/* return string length (number of characters stored) */
int slen(string s)
{
    if (s == NULL)
        return -1; /* or 0 depending on what you prefer; -1 signals error */
    return s->length;
}

/* print characters of the string without adding a newline */
void printString(string s)
{
    if (s == NULL)
        return;
    for (int i = 0; i < slen(s); ++i)
    {
        putchar(s->data[i]);
    }
}