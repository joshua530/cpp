#include <iostream>

int numTargetOccurencesIteration(int target, int nums[], int size)
{
    int occurences = 0;
    for (int i = 0; i < size; ++i)
        if (nums[i] == target)
            ++occurences;
    return occurences;
}

int numTargetOccurencesRecursion(int target, int nums[], int size)
{
    if (size == 0)
        return 0;
    int targetCountAllButLast =
        numTargetOccurencesRecursion(target, nums, size - 1);
    int targetCountLast = (nums[size - 1] == target) ? 1 : 0;
    return targetCountAllButLast + targetCountLast;
}

int main(int argc, char *argv[])
{
    int num = 2;
    int nums[] = {2, 43, 10089, 23, 2, 55, 2, 2, 23, 5, 6, 567, 897, 43, 63, 2};
    std::cout << numTargetOccurencesIteration(num, nums, 14) << "\n";
    std::cout << numTargetOccurencesRecursion(num, nums, 14) << "\n";
}
