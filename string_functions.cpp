#include <iostream>

typedef char *arrayString;

char characterAt(arrayString s, int position)
{
    return s[position];
}

/**
 * finds the length of a string, excluding the null terminating character
 */
int findLength(arrayString s)
{
    int len = 0;
    while (s[len] != 0) {
        ++len;
    }
    return len;
}

/**
 * appends characters in the second string to the end of the first string
 */
void concat(arrayString &s1, arrayString s2)
{
    int len_s1 = findLength(s1);
    int len_s2 = findLength(s2);

    arrayString newString = new char[len_s1 + len_s2 + 1];

    int newStringPos = 0;
    for (int i = 0; i < len_s1; ++i) {
        newString[newStringPos] = s1[i];
        ++newStringPos;
    }
    for (int i = 0; i < len_s2; ++i) {
        newString[newStringPos] = s2[i];
        ++newStringPos;
    }
    newString[newStringPos] = 0;

    delete[] s1;
    s1 = newString;
}

void append(arrayString &s, char toAppend)
{
    int len = findLength(s);

    arrayString newString = new char[len + 2];
    for (int i = 0; i < len; ++i) {
        newString[i] = s[i];
    }

    newString[len] = toAppend;
    newString[len + 1] = 0;

    delete[] s;
    s = newString;
}
