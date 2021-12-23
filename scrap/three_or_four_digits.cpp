#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    int total = 0;
    char currentChar;

    cout << "Enter any number: ";

    currentChar = cin.get();
    total += (currentChar - 48);

    currentChar = cin.get();
    while (currentChar != 10) // we haven't reached a carriage return character yet
    {
        total = (total * 10) + (currentChar - '0');
        currentChar = cin.get();
    }

    cout << "The number entered is " << total << endl;
}
