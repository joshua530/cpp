#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int numVowels = 0;

    cout << "Enter any number of characters: ";

    char current = cin.get();

    while (current != 10) {
        for (char vowel : vowels) {
            if (current == vowel)
                ++numVowels;
        }
        current = cin.get();
    }

    cout << "You have entered " << numVowels << " vowels." << endl;
}
