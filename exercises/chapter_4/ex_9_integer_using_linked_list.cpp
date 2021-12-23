#include <iostream>

struct IntNode {
    int num;
    IntNode *next;
};

typedef IntNode *intList; // integer list

using std::cout;

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

int main(int argc, char *argv[])
{
    intList theList = intToList(21);
    intList theList2 = intToList(149);
    cout << "";
}
