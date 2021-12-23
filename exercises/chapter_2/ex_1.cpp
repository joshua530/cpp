#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    int initial = 8;
    for (int i = 0; i < 4; ++i) {
        for (int spaces = 0; spaces <= i; ++spaces) {
            cout << ' ';
        }

        for (int j = 0; j < initial; ++j) {
            cout << "#";
        }

        cout << endl;
        initial -= 2;
    }
}
