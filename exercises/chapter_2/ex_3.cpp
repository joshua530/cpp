#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    int spacesSet1 = 0;
    int spacesSet2 = 12;
    int numHashes = 1;

    for (int i = 1; i <= 8; ++i) {
        for (int spaces1 = 0; spaces1 < spacesSet1; ++spaces1) cout << ' ';
        for (int hashes = 1; hashes <= numHashes; ++hashes) cout << '#';
        for (int spaces2 = 0; spaces2 < spacesSet2; ++spaces2) cout << ' ';
        for (int hashes = 1; hashes <= numHashes; ++hashes) cout << '#';
        cout << endl;

        if (i < 4) {
            ++spacesSet1;
            spacesSet2 -= 4;
            ++numHashes;
        } else if (i >= 5) {
            --spacesSet1;
            spacesSet2 += 4;
            --numHashes;
        }
    }
}
