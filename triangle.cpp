#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    printf("Enter the square size: ");
    int size;
    cin >> size;

    cout << endl;

    for (int i = size; i > 0; --i)
    {
        for (int j = 1; j <= i; ++j)
            cout << "#";
        cout << endl;
    }
}
