#include <iostream>

#include "utils.cpp"

using std::cout;
using std::endl;

int main()
{
    const int ARRAY_SIZE = 7;
    int items[ARRAY_SIZE] = {2, 4, 2, 5, 1, 3, 2};

    const int HISTOGRAM_SIZE = ARRAY_SIZE + 1;
    int histogram[HISTOGRAM_SIZE] = {0};

    // store frequencies in histogram
    for (int i = 0; i < ARRAY_SIZE; ++i) ++histogram[items[i]];

    // get mode from histogram
    int mostUsedNumber;
    int highestFrequency = 0;
    for (int i = 0; i < HISTOGRAM_SIZE; ++i) {
        if (histogram[i] > highestFrequency) {
            highestFrequency = histogram[i];
            mostUsedNumber = i;
        }
    }

    cout << "Mode = " << mostUsedNumber << " with a frequency of "
         << highestFrequency << endl;
}
