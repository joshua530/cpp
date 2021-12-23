#include <iostream>

struct stringNode {
    char character;
    stringNode *next;
};

typedef stringNode *listString;

void concatenate(listString &a, const listString &b)
{
    stringNode *iteratorA = a;
    if (iteratorA != NULL)
        while (iteratorA->next != NULL)
            iteratorA = iteratorA->next;

    stringNode *iteratorB = b;
    stringNode *tmp;
    while (iteratorB != NULL) {
        tmp = new stringNode;
        tmp->character = iteratorB->character;
        tmp->next = NULL;

        if (iteratorA == NULL) {
            a = iteratorA = tmp;
        } else {
            iteratorA->next = tmp;
            iteratorA = iteratorA->next;
        }

        iteratorB = iteratorB->next;
    }
}

using std::cout;

int main(int argc, char *argv[])
{
    stringNode *n = new stringNode;
    n->character = 'a';
    stringNode *n2 = new stringNode;
    n2->character = 'b';
    n->next = n2;
    n2->next = NULL;

    stringNode *n3 = new stringNode;
    n3->character = 'c';
    stringNode *n4 = new stringNode;
    n4->character = 'd';
    n3->next = n4;
    n4->next = NULL;

    listString s = n;
    listString s2 = n3;
    n = n2 = n3 = n4 = NULL;
    concatenate(s, s2);

    stringNode *a = new stringNode;
    a->character = 'f';
    a->next = NULL;
    listString t = NULL;
    listString t2 = a;
    a = NULL;
    concatenate(t, t2);
    cout << "";
}
