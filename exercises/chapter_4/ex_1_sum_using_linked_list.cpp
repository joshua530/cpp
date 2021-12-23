#include <iostream>

struct number {
    int num;
    number *next;
};

typedef number *numberList;

using std::cin;
using std::cout;

double findSum(const numberList &);
void addNum(numberList &, int);

int main(int argc, char *argv[])
{
    numberList numList = NULL;

    int n;
    cout << "Enter a number. Enter -1 when done: ";
    cin >> n;

    while (n != -1) {
        addNum(numList, n);
        cout << "Enter a number. Enter -1 when done: ";
        cin >> n;
    }

    double sum = findSum(numList);

    cout << "The sum is " << sum << "\n";
}

double findSum(const numberList &n)
{
    double sum = 0.0;
    number *iterator = n;

    while (iterator != NULL) {
        sum += iterator->num;
        iterator = iterator->next;
    }
    return sum;
}

void addNum(numberList &n, int num)
{
    number *newNum = new number;
    newNum->num = num;
    newNum->next = NULL;

    if (n == NULL) {
        n = newNum;
        return;
    }

    number *newList = n;
    while (newList->next != NULL) {
        newList = newList->next;
    }
    newList->next = newNum;
}
