#include <iostream>

// heap - tree in which each node value is higher than any in the left or right
// subtree

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
};

bool subTreesLessThanOrEquivalent(TreeNode *root, int value);

bool isHeap(TreeNode *root)
{
    return subTreesLessThanOrEquivalent(root, root->value);
}

bool subTreesLessThanOrEquivalent(TreeNode *root, int value)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL) {
        if (root->value <= value)
            return true;
        else
            return false;
    }
    return subTreesLessThanOrEquivalent(root->left, root->value) &&
           subTreesLessThanOrEquivalent(root->right, root->value) &&
           root->value <= value;
}

int main(int argc, char *argv[])
{
    TreeNode *a = new TreeNode;
    a->value = 5;
    TreeNode *b = new TreeNode;
    b->value = 4;
    TreeNode *c = new TreeNode;
    c->value = 3;
    a->left = b;
    a->right = c;

    TreeNode *d = new TreeNode;
    d->value = 2;
    TreeNode *e = new TreeNode;
    e->value = 0;
    b->left = d;
    b->right = e;
    d->right = NULL;
    d->left = NULL;
    e->right = NULL;
    e->left = NULL;

    TreeNode *f = new TreeNode;
    f->value = 2;
    TreeNode *g = new TreeNode;
    g->value = 1;
    c->left = f;
    c->right = g;
    f->right = NULL;
    f->left = NULL;
    f->right = NULL;
    f->left = NULL;

    std::cout << (isHeap(a) ? "true" : "false") << "\n";
}
