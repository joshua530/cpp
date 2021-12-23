#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    cout << "Enter any number of words: ";
    char currentChar = cin.get();
    char previousChar = '\0';
    int numWords = 0;
    bool streamEnded = false;
    std::string longestWord = "";
    std::string currentWord = "";

    while (!streamEnded) {
        if (currentChar == ' ' &&
            (previousChar != '\0' || previousChar != ' ')) {  // word terminated
            ++numWords;
            if (currentWord.length() > longestWord.length())
                longestWord = currentWord;
            currentWord = "";
        } else if (currentChar != ' ' && currentChar != 10)
            // we're in a word which is yet to be terminated
            currentWord += currentChar;

        previousChar = currentChar;
        currentChar = cin.get();

        if (currentChar == 10) {  // EOL, character stream terminated
            if (previousChar != ' ')
                ++numWords;

            if (currentWord.length() > longestWord.length())
                longestWord = currentWord;

            streamEnded = true;
        }
    }

    cout << "You have entered " << numWords << " words." << endl;
    cout << "Longest word is " << longestWord << endl;
}
