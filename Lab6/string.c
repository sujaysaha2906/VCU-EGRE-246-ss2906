#include "string.h"
#include <stdlib.h>

string screate()
{
    string s = (string)malloc(sizeof(struct stringType));
    if (s == NULL)
        return NULL;
    s->length = 0;
    return s;
}

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
}

int slen(string s)
{
    if (s == NULL)
        return -1;
    return s->length;
}

void printString(string s)
{
    if (s == NULL)
        return;
    for (int i = 0; i < s->length; ++i)
    {
        putchar(s->data[i]);
    }
}

int scmp(string s1, string s2)
{
    if (!s1 || !s2)
        return 0;
    int n = (s1->length < s2->length) ? s1->length : s2->length;
    for (int i = 0; i < n; i++)
    {
        if (s1->data[i] != s2->data[i])
        {
            return (s1->data[i] - s2->data[i]);
        }
    }
    return (s1->length - s2->length);
}

/* concatenate src onto dest in place, return dest */
string scat(string dest, string src)
{
    if (!dest || !src)
        return NULL;

    int i = 0;
    int total = dest->length;

    while (i < src->length && total < MAX_STRING_SIZE)
    {
        dest->data[total++] = src->data[i++];
    }

    dest->length = total;
    return dest;
}

/* helpers */
static char toUpperChar(char c)
{
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    return c;
}

static char toLowerChar(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    return c;
}

string sToUpper(string s)
{
    if (!s)
        return NULL;
    string result = screate();
    if (!result)
        return NULL;

    for (int i = 0; i < s->length && i < MAX_STRING_SIZE; i++)
    {
        result->data[i] = toUpperChar(s->data[i]);
    }
    result->length = s->length;
    return result;
}

string sToLower(string s)
{
    if (!s)
        return NULL;
    string result = screate();
    if (!result)
        return NULL;

    for (int i = 0; i < s->length && i < MAX_STRING_SIZE; i++)
    {
        result->data[i] = toLowerChar(s->data[i]);
    }
    result->length = s->length;
    return result;
}