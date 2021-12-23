#include <iostream>

using std::cout;

int iterativeArraySum(int array[], int size)
{
    int total = 0;
    for (int i = 0; i < size; ++i) {
        total += array[i];
    }
    return total;
}

int arraySumRecursive(int array[], int size)
{
    if (size == 0)
        return 0;
    int lastNum = array[size - 1];
    int sumAllButLast = arraySumRecursive(array, size - 1);
    return lastNum + sumAllButLast;
}

int numZerosRecursive(int array[], int size)
{
    if (size == 0)
        return 0;
    int totalZeroCountExceptLast = numZerosRecursive(array, size - 1);
    int zeroCount = (array[size - 1] == 0) ? 1 : 0;
    return zeroCount + totalZeroCountExceptLast;
}

struct ListNode {
    int num;
    ListNode *next;
};
typedef ListNode *NumList;

int negativeNumsTotalRecursive(NumList l)
{
    if (l == NULL)
        return 0;
    int negativeNumsWithoutCurrent = negativeNumsTotalRecursive(l->next);
    int negativeNumsCurrent = (l->num < 1) ? 1 : 0;
    return negativeNumsCurrent + negativeNumsWithoutCurrent;
}

int main(int argc, char *argv[])
{
    NumList nums;

    ListNode *num = new ListNode;
    num->num = 1;
    ListNode *num2 = new ListNode;
    num2->num = -1;
    ListNode *num3 = new ListNode;
    num3->num = -2;
    ListNode *num4 = new ListNode;
    num4->num = 3;
    ListNode *num5 = new ListNode;
    num5->num = -4;
    num->next = num2;
    num2->next = num3;
    num3->next = num4;
    num4->next = num5;
    num5->next = NULL;
    nums = num;
    num = num2 = num3 = num4 = num5 = NULL;

    cout << negativeNumsTotalRecursive(nums) << "\n";
}
