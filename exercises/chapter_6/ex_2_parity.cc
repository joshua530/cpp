#include <iostream>

bool evenParityIteration(int binaryString[], int size)
{
    int totalOnes = 0;
    for (int i = 0; i < size; ++i)
        if (binaryString[i] == 1)
            ++totalOnes;
    return totalOnes % 2 == 0;
}

bool evenParityRecursion(int binaryString[], int size)
{
    if (size < 1)
        return true;
    bool evenParityAllButLast = evenParityRecursion(binaryString, size - 1);
    int evenParityLast = true;
    if (binaryString[size - 1] == 1)
        evenParityLast = false;

    bool overallEvenParity = true;
    if (!evenParityLast && evenParityAllButLast)
        overallEvenParity = false;
    if (!evenParityAllButLast && evenParityLast)
        overallEvenParity = false;

    return overallEvenParity;
}

using std::cout;

int main(int argc, char *argv[])
{
    int boolString[] = {1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0};
    std::string iterativeParity =
        (evenParityIteration(boolString, 14)) ? "even" : "odd";
    cout << iterativeParity << "\n";

    std::string recursiveParity =
        (evenParityRecursion(boolString, 14)) ? "even" : "odd";
    cout << recursiveParity << "\n";
}
