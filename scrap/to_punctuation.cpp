#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    char current;
    int total = 0;
    char outputChar;

    cout << "Enter a number from 1-8: ";
    current = cin.get();
    while (current != 10) {
        total = (total * 10) + (current - '0');
        current = cin.get();
    }

    switch (total) {
        case 1:
            outputChar = '!';
            break;
        case 2:
            outputChar = '?';
            break;
        case 3:
            outputChar = ',';
            break;
        case 4:
            outputChar = '.';
            break;
        case 5:
            outputChar = ' ';
            break;
        case 6:
            outputChar = ';';
            break;
        case 7:
            outputChar = '"';
            break;
        case 8:
            outputChar = '\'';
            break;
        default:
            outputChar = '\0';
    }

    cout << "The character is " << outputChar << endl;
}
