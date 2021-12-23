#include <iostream>

struct Node {
    int bit;
    Node *next;
};

bool hasEvenParityIterative(Node *root)
{
    int numOnes = 0;

    for (Node *n = root; n != NULL; n = n->next)
        if (n->bit == 1)
            ++numOnes;
    return (numOnes % 2) == 0;
}

bool hasEvenParityRecursive(Node *root)
{
    if (root == NULL)
        return true;
    bool restHaveEvenParity = hasEvenParityRecursive(root->next);
    bool currentHasEvenParity = (root->bit == 1) ? false : true;
    bool overallEvenParity = true;
    if (!restHaveEvenParity && currentHasEvenParity)
        overallEvenParity = false;
    if (!currentHasEvenParity && restHaveEvenParity)
        overallEvenParity = false;
    return overallEvenParity;
}

int main(int argc, char *argv[])
{
    Node *a = new Node;
    a->bit = 1;
    Node *b = new Node;
    b->bit = 1;
    Node *c = new Node;
    c->bit = 0;
    Node *d = new Node;
    d->bit = 1;
    Node *e = new Node;
    e->bit = 0;
    Node *f = new Node;
    f->bit = 0;
    Node *g = new Node;
    g->bit = 1;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = NULL;

    std::string parity = (hasEvenParityIterative(a)) ? "even" : "odd";
    std::cout << parity << "\n";

    parity = (hasEvenParityRecursive(a)) ? "even" : "odd";
    std::cout << parity << "\n";
}
