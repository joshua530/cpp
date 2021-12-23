#include <iostream>

#include "insertion_sort.cpp"

using std::cout;
using std::endl;

void sort(int *, int);

int main(int argc, char const *argv[])
{
    const int ARRAY_SIZE = 12;
    int data[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};

    sort(data, ARRAY_SIZE);

    int highestFrequency = 0;
    int currentFrequency = 0;
    int highestSoFar;

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        ++currentFrequency;

        // if (nums[i] is the last in series of numbers)
        if (i == ARRAY_SIZE - 1 || data[i] != data[i + 1]) {
            if (currentFrequency > highestFrequency) {
                highestSoFar = data[i];
                highestFrequency = currentFrequency;
            }
            currentFrequency = 0;
        }
    }

    cout << "Most used number is " << highestSoFar << " and appears "
         << highestFrequency << " times." << endl;

    return 0;
}

/**
 * performs insertion sort
 */
void sort(int *items, int arraySize)
{
    int start = 0;
    for (int i = start; i < arraySize; ++i)
        for (int j = i; j > start && items[j] < items[j - 1]; --j) {
            int tmp = items[j];
            items[j] = items[j - 1];
            items[j - 1] = tmp;
        }
}
