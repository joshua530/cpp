#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    char current;
    int total = 0;
    char outputChar;

    cout << "Enter a number from 1-26: ";
    current = cin.get();
    while (current != 10)
    {
        total = (total * 10) + (current - '0');
        current = cin.get();
    }
    outputChar = total + 'A' - 1;
    cout << "Upper case is " << outputChar << endl;
}
