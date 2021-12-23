#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    int total = 0;
    char currentChar;

    cout << "Enter a list of comma separated numbers: ";

    do
    {
        currentChar = cin.get();
        while (currentChar != ',' && currentChar != 10) // not EOL and not number separator
        {
            total = total * 10 + (currentChar - '0');
            currentChar = cin.get();
        }
        cout << "Number is " << total << endl;
        total = 0;
    } while (currentChar != 10); // not EOL
}
