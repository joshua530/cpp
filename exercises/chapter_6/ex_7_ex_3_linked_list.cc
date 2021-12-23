#include <iostream>

struct Node {
    int num;
    Node *next;
};

int targetCountIterative(Node *root, int target)
{
    int targetCount = 0;
    for (Node *n = root; n != NULL; n = n->next)
        if (n->num == target)
            ++targetCount;
    return targetCount;
}

int targetCountRecursive(Node *root, int target)
{
    if (root == NULL)
        return 0;
    int numTargetInRest = targetCountRecursive(root->next, target);
    int numTarget = (root->num == target) ? 1 : 0;
    return numTarget + numTargetInRest;
}

int main(int argc, char *argv[])
{
    Node *a = new Node;
    a->num = 1;
    Node *b = new Node;
    b->num = 2;
    Node *c = new Node;
    c->num = 3;
    Node *d = new Node;
    d->num = 3;
    Node *e = new Node;
    e->num = 10;
    Node *f = new Node;
    f->num = 3;
    Node *g = new Node;
    g->num = 10;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = NULL;

    std::cout << targetCountIterative(a, 3) << "\n";
    std::cout << targetCountRecursive(a, 1) << "\n";
}
