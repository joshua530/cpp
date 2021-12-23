#include <iostream>

bool isSorted(int theArray[], int size)
{
    const bool ASCENDING = 0;
    const bool DESCENDING = 1;

    if (size <= 1)
        return true;

    bool expected = theArray[0] > theArray[1] ? DESCENDING : ASCENDING;

    for (int i = 0; i < size; ++i) {
        if (i < (size - 1)) {  // don't move past array bounds
            if (expected == DESCENDING && theArray[i] < theArray[i + 1])
                return false;
            else if (expected == ASCENDING && theArray[i] > theArray[i + 1])
                return false;
        }
    }
    return true;
}

using std::cout;

int main(int argc, char const *argv[])
{
    int testData[] = {1, 2, 3, 4, 5};
    int testData2[] = {5, 4, 3, 2, 1};
    int testData3[] = {1, 2, 3, 1, 4, 5};
    int testData4[] = {1, 2};
    int testData5[] = {};
    int testData6[] = {1};

    cout << isSorted(testData, 5) << "\n";
    cout << isSorted(testData2, 5) << "\n";
    cout << isSorted(testData3, 6) << "\n";
    cout << isSorted(testData4, 2) << "\n";
    cout << isSorted(testData5, 0) << "\n";
    cout << isSorted(testData6, 1) << "\n";
    return 0;
}
