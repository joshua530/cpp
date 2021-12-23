#include <iostream>

typedef char *arrayString;

using std::cout;

int strLength(const arrayString &s)
{
    int len = 0;

    while (s[len] != 0) {
        ++len;
    }
    return len;
}

arrayString substring(const arrayString &s, int start, int len)
{

    arrayString str = new char[len + 1];

    int begin = start - 1;
    int end = begin + len - 1;
    int currentPos = 0;
    for (int i = begin; i <= end; ++i) {
        str[currentPos] = s[i];
        ++currentPos;
    }
    str[currentPos] = 0;

    return str;
}

/**
 * appends characters in the second string to the end of the first string
 */
void concat(arrayString &s1, arrayString s2)
{
    int len_s1 = strLength(s1);
    int len_s2 = strLength(s2);

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
    int len = strLength(s);

    arrayString newString = new char[len + 2];
    for (int i = 0; i < len; ++i) {
        newString[i] = s[i];
    }

    newString[len] = toAppend;
    newString[len + 1] = 0;

    delete[] s;
    s = newString;
}

bool equals(const arrayString &a, const arrayString &b)
{
    int lenA = strLength(a);
    int lenB = strLength(b);

    // are corresponding characters equal?
    int a_index, b_index;
    a_index = b_index = 0;
    for (; a_index < lenA, b_index < lenB; ++a_index, ++b_index)
        if (a[a_index] != b[b_index])
            return false;

    // are strings of the same length?
    if (a_index != lenA)
        return false;
    if (b_index != lenB)
        return false;

    return true;
}

void replaceString(arrayString &source, arrayString target,
                   arrayString replaceText)
{
    int sourceLen = strLength(source);
    int targetLen = strLength(target);
    int replacementLen = strLength(replaceText);

    int numReplacements = 0;
    for (int i = 0; i < sourceLen; ++i) {
        arrayString substr = substring(source, i + 1, targetLen);
        if (equals(substr, target))
            ++numReplacements;
    }

    int lenReplaced =
        sourceLen + ((replacementLen - targetLen) * numReplacements) + 1;

    arrayString newStr = new char[lenReplaced];

    int sourcePos = 0;
    int newStrPos = 0;
    while (sourcePos < sourceLen) {
        arrayString tmpStr = substring(source, sourcePos + 1, targetLen);
        if (equals(tmpStr, target)) {
            concat(newStr, replaceText);
            sourcePos += targetLen;
            newStrPos += replacementLen;
        } else {
            append(newStr, source[sourcePos]);
            ++sourcePos;
            ++newStrPos;
        }
    }
    newStr[newStrPos] = 0;

    delete[] source;
    source = newStr;
}

int main(int argc, char const *argv[])
{
    arrayString a = new char[9];
    a[0] = 'f';
    a[1] = 'g';
    a[2] = 'h';
    a[3] = 'i';
    a[4] = 'f';
    a[5] = 'g';
    a[6] = 'm';
    a[7] = 'n';
    a[8] = 0;

    arrayString b = new char[3];
    b[0] = 'f';
    b[1] = 'g';
    b[2] = 0;

    arrayString c = new char[4];
    c[0] = 'r';
    c[1] = 'e';
    c[2] = 'p';
    c[3] = 0;

    arrayString d = new char[2];
    d[0] = 'e';
    d[1] = 0;
    arrayString e = new char[5];
    e[0] = 'n';
    e[1] = 'i';
    e[2] = 'n';
    e[3] = 'e';
    e[4] = 0;

    arrayString f = new char[2];
    f[0] = 'e';
    f[1] = 0;
    arrayString r = new char[2];
    r[0] = 'e';
    r[1] = 0;
    arrayString g = new char[4];
    g[0] = 'e';
    g[1] = 'g';
    g[2] = 'g';
    g[3] = 0;

    replaceString(a, b, c);
    replaceString(c, d, e);
    replaceString(f, r, g);

    cout << a << "\n"; // rephirepmn
    cout << c << "\n"; // rninep
    cout << f << "\n"; // egg
}
