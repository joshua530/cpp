#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int charToInt(char);
int doubleDigitValue(int);

int main(int argc, char *argv[])
{
    char digit;
    // keep track of both even and odd lengths since we have no prior knowledge
    // of the length of the input
    int oddLengthChecksum = 0, evenLengthChecksum = 0;
    int currentPosition = 1;
    int current;

    cout << "Enter id to validate: ";
    digit = cin.get();

    while (digit !=
           10)  // 10 is the integer value for the carriage return character
    {
        current = charToInt(digit);
        if (currentPosition % 2 == 0) {
            oddLengthChecksum += doubleDigitValue(current);
            evenLengthChecksum += current;
        } else {
            oddLengthChecksum += current;
            evenLengthChecksum += doubleDigitValue(current);
        }
        digit = cin.get();
        ++currentPosition;
    }

    int trueChecksum;
    if ((currentPosition - 1) % 2 == 0)
        trueChecksum = evenLengthChecksum;
    else
        trueChecksum = oddLengthChecksum;

    cout << trueChecksum << endl;
    if (trueChecksum % 10 == 0)
        cout << "Number is a valid id\n";
    else
        cout << "Number is an invalid id\n";
}

int doubleDigitValue(int n)
{
    int doubleValue = n * 2;
    int sum = 0;

    if (doubleValue >= 10)
        sum = 1 + doubleValue % 10;
    else
        sum = doubleValue;
    return sum;
}

int charToInt(char c)
{
    int asciiNum = (int)c;
    // 48 is the difference between the ascii and desired values
    // 48 is the ascii value for the character '0'
    int desired = asciiNum - 48;
    // int desired = c - '0';
    return desired;
}
