#include <iostream>

// array string implementation where the first character contains the length of
// the string. The length of the string is exclusive of the first part that
// shows the string's length
typedef char *arrayString;

using std::cout;

int strLength(arrayString s)
{
    return s[0];
}

void append(arrayString &s, char toAppend)
{
    int oldStrLen = strLength(s);
    int newStrLen = oldStrLen + 1;
    arrayString newString = new char[newStrLen + 1]; // extra space for length

    newString[0] = newStrLen;
    for (int i = 1; i <= oldStrLen; ++i)
        newString[i] = s[i];
    newString[newStrLen] = toAppend;

    delete[] s;
    s = newString;
}

void output(const arrayString &s)
{
    for (int i = 1; i <= s[0]; ++i)
        cout << s[i];
    cout << "\n";
}

char characterAt(const arrayString &s, int position)
{
    if (position < 1 || position > strLength(s))
        return 0;
    return s[position];
}

void concatenate(arrayString &s, const arrayString &append)
{
    int oldStrLen = strLength(s);
    int appendStrLen = strLength(append);
    int newStrLen = oldStrLen + appendStrLen;

    arrayString newStr = new char[newStrLen + 1];
    newStr[0] = newStrLen;
    for (int i = 1; i <= oldStrLen; ++i)
        newStr[i] = s[i];
    for (int i = 1; i <= appendStrLen; ++i)
        newStr[oldStrLen + i] = append[i];

    delete[] s;
    s = newStr;
}

int main(int argc, char *argv[])
{
    arrayString a = new char[1];
    a[0] = 0;
    arrayString c = new char[1];
    c[0] = 0;
    arrayString b = new char[3];
    b[0] = 2;
    b[1] = 'd';
    b[2] = 'e';
    concatenate(a, b);
    output(a);
    cout << characterAt(a, 1) << "\n";
    cout << characterAt(c, 1) << "\n";
}
