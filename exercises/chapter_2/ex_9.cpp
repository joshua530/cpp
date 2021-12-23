#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char getLetter(int);
bool isLetter(char);
int getLetterNum(char);

int main(int argc, char const *argv[])
{
    // tracks number of words entered, longest word, greatest number of vowels
    // per word and most common letter used
    cout << "Enter any number of words: ";
    char currentChar = cin.get();
    char previousChar = '\0';

    int numWords = 0;

    std::string longestWord = "";
    std::string currentWord = "";

    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int numVowels = 0;
    int greatestNumVowels = 0;
    std::string wordWithGreatestNumVowels = "";

    int letterCount[27] = {0};
    int letterNum;

    bool streamTerminated = false;
    while (!streamTerminated) {
        if (currentChar == ' ' &&
            (previousChar != '\0' || previousChar != ' ')) {  // word terminated
            ++numWords;
            if (currentWord.length() > longestWord.length())
                longestWord = currentWord;
            if (numVowels > greatestNumVowels) {
                wordWithGreatestNumVowels = currentWord;
                greatestNumVowels = numVowels;
            }

            currentWord = "";
            numVowels = 0;
        } else if (currentChar != ' ' && currentChar != 10) {
            // we're in a word which is yet to be terminated
            currentWord += currentChar;
            for (char vowel : vowels)
                if (currentChar == vowel)
                    ++numVowels;
            if (isLetter(currentChar)) {
                letterNum = getLetterNum(currentChar);
                ++letterCount[letterNum];
            }
        }

        previousChar = currentChar;
        currentChar = cin.get();

        if (currentChar == 10) {  // EOL. character stream terminated
            if (previousChar != ' ')
                ++numWords;

            if (currentWord.length() > longestWord.length())
                longestWord = currentWord;
            if (numVowels > greatestNumVowels) {
                wordWithGreatestNumVowels = currentWord;
                greatestNumVowels = numVowels;
            }
            streamTerminated = true;
        }
    }

    int greatestLetterCount = 0;
    char greatestLetter;
    for (int i = 1; i < 27; ++i) {
        if (letterCount[i] > greatestLetterCount) {
            greatestLetterCount = letterCount[i];
            greatestLetter = getLetter(i);
        }
    }

    cout << "You have entered " << numWords << " words." << endl;
    cout << "Longest word is " << longestWord << " of length "
         << longestWord.length() << endl;
    cout << "Word with greatest number of vowels is "
         << wordWithGreatestNumVowels << " with " << greatestNumVowels
         << " vowels." << endl;
    cout << "The most common letter is " << greatestLetter
         << " which has been used " << greatestLetterCount << " times." << endl;
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
