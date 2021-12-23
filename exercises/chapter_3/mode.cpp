#include <iostream>

using namespace std;

int mode(int *array, int lenArray, int maxValue)
{
    int histogram[maxValue + 1] = {0};

    for (int i = 0; i < lenArray; i++) histogram[array[i]]++;

    int mostUsed = 0;
    int mostUsedCount = histogram[0];
    for (int i = 0; i <= maxValue; ++i)
        if (histogram[i] > mostUsedCount) {
            mostUsed = i;
            mostUsedCount = histogram[i];
        }

    return mostUsed;
}

int main(int argc, char const *argv[])
{
    int nums[] = {9, 1, 2, 3, 9, 2, 4, 5, 1, 9, 8};
    cout << mode(nums, 11, 9) << "\n";
    return 0;
}
