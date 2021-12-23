#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char getLetter(int);
bool isLetter(char);
int getLetterNum(char);

int main(int argc, char const *argv[])
{
    int letterCount[27] = {0};

    cout << "Enter any number of characters: ";

    char current = cin.get();
    int letterNum;

    while (current != 10) {
        if (isLetter(current)) {
            letterNum = getLetterNum(current);
            ++letterCount[letterNum];
        }
        current = cin.get();
    }

    for (int i = 1; i < 27; ++i) {
        cout << getLetter(i) << " = " << letterCount[i] << endl;
    }
}

char getLetter(int letterPos)
{
    return letterPos + ('a' - 1);
}

bool isLetter(char letter)
{
    // is lower case or is upper case
    return (letter <= 122 && letter >= 97) || (letter >= 65 && letter <= 90);
}

int getLetterNum(char letter)
{
    if (islower(letter))
        return (letter - 'a') + 1;
    else if (isupper(letter))
        return (letter - 'A') + 1;
    return 0;
}
