#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    int numSpaces = 3;
    int numHashes = 2;
    for (int i = 1; i <= 8; ++i) {
        for (int spaces = 0; spaces <= numSpaces; ++spaces) cout << ' ';
        for (int hashes = 0; hashes <= numHashes; ++hashes) cout << '#';
        cout << endl;

        if (i < 4) {
            --numSpaces;
            numHashes += 2;
        } else if (i >= 5) {
            ++numSpaces;
            numHashes -= 2;
        }
    }
}
