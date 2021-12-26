#include <iostream>
using std::cin;
using std::cout;
using std::ios;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <list>
using std::iterator;
using std::list;

#include <string.h>

list<string> readWordFile(char *fileName)
{
    list<string> words;
    ifstream wordFile(fileName, ios::in);
    if (wordFile.fail()) {
        cout << "File open failed";
        return words;
    }
    char currentWord[30];
    while (wordFile >> currentWord) {
        if (strchr(currentWord, '\'') == 0) {
            string tmp(currentWord);
            words.push_back(tmp);
        }
    }
    return words;
}

void displayList(const list<string> &wordList)
{
    list<string>::const_iterator iter = wordList.begin();
    while (iter != wordList.end()) {
        cout << iter->c_str() << "\n";
        ++iter;
    }
}

int countWordsWithoutLetter(const list<string> &words, char letter)
{
    int wordsWithoutLetter = 0;
    list<string>::const_iterator iter = words.begin();
    while (iter != words.end()) {
        if (iter->find(letter) == string::npos)
            ++wordsWithoutLetter;
        ++iter;
    }
    return wordsWithoutLetter;
}

void removeWordsOfWrongLength(list<string> &words, int requiredLength)
{
    list<string>::iterator iter = words.begin();
    while (iter != words.end()) {
        if (iter->length() != requiredLength)
            iter = words.erase(iter);
        else
            ++iter;
    }
}

bool numberInPattern(const list<int> &pattern, int number)
{
    list<int>::const_iterator iter = pattern.begin();
    while (iter != pattern.end()) {
        if (*iter == number)
            return true;
        ++iter;
    }
    return false;
}

/**
 * Finds only words that match the given pattern
 */
list<string> reduceByPattern(const list<string> &wordList, char letter,
                             const list<int> &pattern)
{
    list<string> patternMatches;
    list<string>::const_iterator iter = wordList.begin();

    while (iter != wordList.end()) {
        list<int>::const_iterator patternIter = pattern.begin();
        while (patternIter != pattern.end()) {
            if ((*iter)[*patternIter] != letter)
                break;
            ++patternIter;
        }
        if (patternIter == pattern.end())
            patternMatches.push_back(*iter);
        ++iter;
    }

    return patternMatches;
}

/**
 * @param pattern a series of numbers representing the positions in which a
 * particular letter appears
 */
bool matchesPattern(string word, char letter, const list<int> &pattern)
{
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == letter && !numberInPattern(pattern, i))
            // letter exists where it is not wanted
            return false;
        else if (word[i] != letter && numberInPattern(pattern, i))
            // letter is absent in a position where it is needed
            return false;
    }
    return true;
}

void removeWordsWithoutLetter(list<string> &words, char letter)
{
    list<string>::const_iterator iter = words.begin();
    while (iter != words.end()) {
        if (iter->find(letter) == string::npos)
            iter = words.erase(iter);
        else
            ++iter;
    }
}

void removeWordsWithLetter(list<string> &words, char letter)
{
    list<string>::const_iterator iter = words.begin();
    while (iter != words.end()) {
        if (iter->find(letter) != string::npos)
            iter = words.erase(iter);
        else
            ++iter;
    }
}

void mostFreqPatternByLetter(list<string> words, char letter,
                             list<int> &mostFreqPattern,
                             int &mostFreqPatternCount)
{
    removeWordsWithoutLetter(words, letter);
    mostFreqPatternCount = 0;
    list<string>::const_iterator iter;

    while (!words.empty()) {
        int currentPatternCount = 0;
        list<int> currentPattern;
        iter = words.begin();
        for (int i = 0; i < iter->length(); ++i) {
            if ((*iter)[i] == letter)
                currentPattern.push_back(i);
        }
        ++currentPatternCount;
        iter = words.erase(iter);

        while (iter != words.end()) {
            if (matchesPattern(*iter, letter, currentPattern)) {
                ++currentPatternCount;
                iter = words.erase(iter);
            } else
                ++iter;
        }
        if (currentPatternCount > mostFreqPatternCount) {
            mostFreqPatternCount = currentPatternCount;
            mostFreqPattern = currentPattern;
        }
    }
}

void displayGuessedLetters(bool letters[26])
{
    cout << "Letters guessed: ";
    for (int i = 0; i < 26; ++i) {
        if (letters[i])
            cout << (char)('a' + i) << " ";
    }
    cout << "\n";
}

int main()
{
    char fileName[] = "words";
    list<string> words = readWordFile(fileName);
    const int wordLength = 8;
    const int maxMisses = 7;

    int discoveredLetterCount = 0;
    int misses = 0;
    removeWordsOfWrongLength(words, 8);
    char revealedWord[wordLength + 1] = "********";
    bool guessedLetters[26] = {false};
    char nextLetter;
    cout << "Word so far " << revealedWord << "\n";

    // play the game
    while (discoveredLetterCount < wordLength && misses < maxMisses) {
        cout << "Letter to guess: ";
        cin >> nextLetter;
        guessedLetters[nextLetter - 'a'] = true;
        int missingCount = countWordsWithoutLetter(words, nextLetter);
        list<int> nextPattern;
        int nextPatternCount;
        mostFreqPatternByLetter(words, nextLetter, nextPattern,
                                nextPatternCount);
        if (missingCount > nextPatternCount) {
            removeWordsWithLetter(words, nextLetter);
            ++misses;
        } else {
            list<int>::const_iterator iter = nextPattern.begin();
            while (iter != nextPattern.end()) {
                revealedWord[*iter] = nextLetter;
                ++iter;
                ++discoveredLetterCount;
            }
            // removeWordsWithLetter(words, nextLetter);
            words = reduceByPattern(words, nextLetter, nextPattern);
        }
        cout << "Word so far: " << revealedWord << "\n";
        displayGuessedLetters(guessedLetters);
    }
    if (misses == maxMisses) {
        cout << "Sorry, you lost. The word I was thinking of is ";
        cout << (words.cbegin())->c_str() << "\n";
    } else {
        cout << "Great job! You win. The word is " << revealedWord << "\n";
    }

    return 0;
}
