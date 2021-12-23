#include <iostream>

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
};

int largestValue(TreeNode *node)
{
    if (node == NULL)
        return 0;
    if (node->right == NULL && node->left == NULL)
        return node->data;

    int largestLeft = largestValue(node->left);
    int largestRight = largestValue(node->right);
    int largest = node->data;
    if (largestLeft > largest)
        largest = largestLeft;
    if (largestRight > largest)
        largest = largestRight;
    return largest;
}

using std::cout;

int main(int argc, char *argv[])
{
    TreeNode *a = new TreeNode;
    a->data = 2;
    TreeNode *b = new TreeNode;
    b->data = 7;
    TreeNode *c = new TreeNode;
    c->data = 5;

    a->left = b;
    a->right = c;

    TreeNode *d = new TreeNode;
    d->data = 2;
    d->left = NULL;
    d->right = NULL;

    TreeNode *e = new TreeNode;
    e->data = 10;
    e->left = NULL;
    e->right = NULL;

    b->left = d;
    b->right = e;

    TreeNode *f = new TreeNode;
    f->data = 16;
    TreeNode *g = new TreeNode;
    g->data = 9;

    c->left = f;
    c->right = g;

    TreeNode *h = new TreeNode;
    h->data = 5;
    h->left = NULL;
    h->right = NULL;

    TreeNode *i = new TreeNode;
    i->data = 11;
    i->left = NULL;
    i->right = NULL;

    f->left = h;
    f->right = i;

    TreeNode *j = new TreeNode;
    j->data = 4;
    j->left = NULL;
    j->right = NULL;

    g->left = j;
    g->right = NULL;

    cout << largestValue(a) << "\n";
}
