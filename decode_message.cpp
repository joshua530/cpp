#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char toLower(int);
char toPunctuation(int);
char toUpper(int);

int main(int argc, char *argv[])
{
    enum mode { UPPERCASE, LOWERCASE, PUNCTUATION };
    mode currentMode = UPPERCASE;

    int digiChar = 0;
    char currentChar;
    char decoded;
    int modulus;
    std::string theMessage = "";

    cout << "Enter a list of comma separated numbers: ";

    do {
        digiChar = 0;
        currentChar = cin.get();
        while (currentChar != ',' &&
               currentChar != 10)  // not EOL and not number separator
        {
            digiChar = digiChar * 10 + (currentChar - '0');
            currentChar = cin.get();
        }

        switch (currentMode) {
            case UPPERCASE:
                modulus = digiChar % 27;
                decoded = toUpper(modulus);
                if (modulus == 0) {
                    currentMode = LOWERCASE;
                    continue;
                }
                break;
            case LOWERCASE:
                modulus = digiChar % 27;
                decoded = toLower(modulus);
                if (modulus == 0) {
                    currentMode = PUNCTUATION;
                    continue;
                }
                break;
            case PUNCTUATION:
                modulus = digiChar % 9;
                decoded = toPunctuation(modulus);
                if (modulus == 0) {
                    currentMode = UPPERCASE;
                    continue;
                }
                break;
        }

        cout << decoded;
    } while (currentChar != 10);  // not EOL

    // std::cout << "The decoded message is '" << theMessage << "'" << endl;
}

char toLower(int charNumber)
{
    return charNumber + 'a' - 1;
}

char toUpper(int charNumber)
{
    return charNumber + 'A' - 1;
}

char toPunctuation(int charNumber)
{
    char outputChar;
    switch (charNumber) {
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

    return outputChar;
}
