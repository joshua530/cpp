#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    enum mode { UPPERCASE, LOWERCASE, PUNCTUATION };
    mode currentMode = UPPERCASE;

    int currentNumber;

    cout << "Enter a series of numbers ending with -1: ";

    cin >> currentNumber;

    while (currentNumber != -1) {
        if (currentMode == UPPERCASE) {
            if (currentNumber % 27 == 0)
                currentMode = LOWERCASE;
        } else if (currentMode == LOWERCASE) {
            if (currentNumber % 27 == 0)
                currentMode = UPPERCASE;
        } else {
            if (currentNumber % 9 == 0)
                currentMode = UPPERCASE;
        }

        cout << "Current mode is " << currentMode << endl;
        cin >> currentNumber;
    }
    return 0;
}
