#include <iostream>

typedef char *arrayString;

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

void testSubstring()
{
    arrayString foo = new char[8];
    foo[0] = 'a';
    foo[1] = 'b';
    foo[2] = 'c';
    foo[3] = 'd';
    foo[4] = 'e';
    foo[5] = 'f';
    foo[6] = 'g';
    foo[7] = 0;

    arrayString bar = substring(foo, 2, 4);
    std::cout << bar << "\n";

    arrayString b = new char[1];
    b[0] = 0;
    std::cout << substring(b, 1, 2) << "\n";

    arrayString c = new char[2];
    b[0] = 'a';
    b[1] = 0;
    std::cout << substring(b, 1, 2) << "\n";
}

int main(int argc, char *argv[])
{
    testSubstring();
}
