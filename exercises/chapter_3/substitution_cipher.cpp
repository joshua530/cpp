#include <ctime>
#include <iostream>
#include <random>

using std::cout;
using std::string;

string encrypt(string, char[]);
int getCharIndex(char);
int getCipherIndex(char, char[], int);
char getChar(int);
string decrypt(string, char[], int);
template <typename T>
bool inArray(T, T *, int);
void generateCipherTable(char *, int);

std::string strArray(int *toPrint, int size)
{
    std::string items = "";
    char tmp[50];

    for (int i = 0; i < size; ++i) {
        sprintf(tmp, "%d ", toPrint[i]);
        items += tmp;
    }
    items.erase(items.find_last_not_of(" ") + 1);
    return items;
}

int main(int argc, char const *argv[])
{
    // char cipherTable[] = {'{', '#', 'V', '+', '~', '.', 'Z', 'I', 'P',
    //                       '$', 'T', 'A', '&', 'B', '<', 'D', 'X', '*',
    //                       'E', 'G', 'C', 'Q', 'R', '=', '@', 'M'};
    char cipherTable[26];
    generateCipherTable(cipherTable, 26);

    string message = "The quick brown fox jumps over the lazy dog";
    string cipher = encrypt(message, cipherTable);
    cout << cipher << "\n";

    string decrypted = decrypt(cipher, cipherTable, 26);
    cout << decrypted << "\n";
    return 0;
}

void generateCipherTable(char *arrayToFill, int arrayLen)
{
    int generatedNumbers[arrayLen] = {0};
    int randomNum = (rand() % 55) + 55;  // generate number between 55 and 110;
    char generatedChar;

    srand(time(NULL));
    for (int i = 0; i < arrayLen; ++i) {
        while (inArray(randomNum, generatedNumbers, arrayLen))
            randomNum = (rand() % 55) + 55;
        generatedNumbers[i] = randomNum;
        generatedChar = (char)randomNum;
        arrayToFill[i] = generatedChar;
    }
}

/**
 * Checks whether needle exists in hayStack
 */
template <typename T>
bool inArray(T needle, T *hayStack, int arrayLen)
{
    for (int i = 0; i < arrayLen; ++i)
        if (needle == hayStack[i])
            return true;
    return false;
}

string encrypt(string toEncrypt, char substitutes[])
{
    string cipher = "";
    int charIndex;

    for (char const &c : toEncrypt) {
        if (isalpha(c)) {
            charIndex = getCharIndex(c);
            cipher += substitutes[charIndex];
        } else {
            cipher += c;
        }
    }

    return cipher;
}

string decrypt(string cipher, char cipherTable[], int tableLength)
{
    string decrypted = "";
    int charIndex;
    char decryptedChar;

    for (const char &c : cipher) {
        charIndex = getCipherIndex(c, cipherTable, tableLength);
        if (charIndex != -1)
            decryptedChar = getChar(charIndex);
        else
            decryptedChar = c;

        decrypted += decryptedChar;
    }

    return decrypted;
}

int getCharIndex(char c)
{
    int asciiVal = toascii(c);

    if (isupper(c))
        asciiVal -= 'A';
    else if (islower(c))
        asciiVal -= 'a';
    return asciiVal;
}

char getChar(int charIndex)
{
    return charIndex + 'a';
}

int getCipherIndex(char c, char cipherTable[], int tableLength)
{
    for (int i = 0; i < tableLength; ++i)
        if (cipherTable[i] == c) {
            cout << "";
            return i;
        }
    return -1;
}
