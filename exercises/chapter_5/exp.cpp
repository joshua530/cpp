// #include "ex_3_4_5_6_variable_length_string.cpp"
#include "ex_6_student_records.cpp"
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

int main(int argc, char *argv[])
{
    int foo[] = {1, 2, 3, 4, 5};
    cout << iterativeArraySum(foo, 5) << "\n";
    cout << arraySumRecursive(foo, 5) << "\n";
}
