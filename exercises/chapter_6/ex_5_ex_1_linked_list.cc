#include <iostream>

struct Node {
    int num;
    Node *next;
};

int sumPositiveIteration(Node *root)
{
    int sum = 0;
    for (Node *n = root; n != NULL; n = n->next)
        if (n->num > 0)
            sum += n->num;
    return sum;
}

int sumPositiveRecursion(Node *root)
{
    if (root == NULL)
        return 0;
    int sumAllButCurrent = sumPositiveRecursion(root->next);
    int sum = 0;
    if (root->num > 0)
        sum += root->num;
    return sum + sumAllButCurrent;
}

int main(int argc, char *argv[])
{
    Node *a = new Node;
    a->num = 1;
    Node *b = new Node;
    b->num = -2;
    Node *c = new Node;
    c->num = 3;
    Node *d = new Node;
    d->num = -4;
    Node *e = new Node;
    e->num = 5;
    Node *f = new Node;
    f->num = -6;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = NULL;

    std::cout << sumPositiveIteration(a) << "\n";
    std::cout << sumPositiveRecursion(a) << "\n";
}
