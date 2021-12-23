#include <iostream>

int sumPositiveIterative(int nums[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (nums[i] > 0)
            sum += nums[i];
    }
    return sum;
}

int sumPositiveRecursive(int nums[], int size)
{
    if (size < 1)
        return 0;
    int sumAllButLast = sumPositiveRecursive(nums, size - 1);
    int lastNum = nums[size - 1];

    if (lastNum > 0)
        return lastNum + sumAllButLast;
    return sumAllButLast;
}

using std::cout;

int main(int argc, const char *argv[])
{
    int nums[] = {1, -1, 2, -3, 3, -2, 4, -5, 5, -4};
    cout << sumPositiveIterative(nums, 10) << "\n";
    cout << sumPositiveRecursive(nums, 10) << "\n";
}
