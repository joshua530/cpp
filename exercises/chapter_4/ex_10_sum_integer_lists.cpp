#include <iostream>

struct IntNode {
    int num;
    IntNode *next;
};

typedef IntNode *intList;

using std::cout;

void append(intList &l, int i);
void prepend(intList &l, int i);
intList intToList(int toStore);
int listToInt(const intList &l);
int sum(const intList &a, const intList &b);
int len(const intList &l);
intList reverse(const intList &toReverse);

void append(intList &l, int i)
{
    IntNode *tmp = new IntNode;
    tmp->num = i;
    tmp->next = NULL;

    IntNode *iterator = l;
    if (iterator == NULL)
        l = tmp;
    else {
        while (iterator->next != NULL)
            iterator = iterator->next;
        iterator->next = tmp;
    }
}

void prepend(intList &l, int i)
{
    IntNode *n = new IntNode;
    n->num = i;
    n->next = l;
    l = n;
}

intList intToList(int toStore)
{
    intList newList = NULL;
    int tmp;

    do {
        tmp = toStore % 10;
        toStore = (toStore - tmp) / 10;
        prepend(newList, tmp);
    } while (toStore != 0);

    return newList;
}

int listToInt(const intList &l)
{
    intList reversed = reverse(l);

    int multiplier = 1;
    IntNode *iterator = reversed;
    int total = 0;
    int n;

    while (iterator != NULL) {
        n = iterator->num;
        total += n * multiplier;
        multiplier *= 10;
        iterator = iterator->next;
    }

    return total;
}

int sum(const intList &a, const intList &b)
{
    return listToInt(a) + listToInt(b);
}

/**
 * Finds the length of an integer list
 */
int len(const intList &l)
{
    int count = 0;
    IntNode *iterator = l;

    while (iterator != NULL) {
        iterator = iterator->next;
        ++count;
    }
    return count;
}

intList reverse(const intList &toReverse)
{
    int count = len(toReverse);

    intList newList;
    if (count == 0) { // there are no numbers to reverse
        newList = NULL;
        return newList;
    }

    int nums[count];
    // copy all numbers in list into array
    IntNode *iterator = toReverse;
    int i = 0;
    while (iterator != NULL) {
        nums[i] = iterator->num;
        ++i;
        iterator = iterator->next;
    }

    // iterate over array in reverse, adding each number to the new list
    IntNode *tmp = NULL;
    for (int j = i - 1; j >= 0; --j) {
        append(tmp, nums[j]);
    }

    return tmp;
}

int main(int argc, char const *argv[])
{
    intList a = intToList(21);
    intList b = intToList(102);
    int total = sum(a, b);
    intList c = NULL;
    intList d = intToList(1);
    int tt = sum(c, d);
}
