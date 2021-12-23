#include <iostream>

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
};

bool rightSubtreeIsBst(TreeNode *rightSubtreeRoot, int value);
bool leftSubtreeIsBst(TreeNode *leftSubtreeRoot, int value);

/**
 * a binary search tree has all the nodes of the left sub tree
 * less than the parent node and all the nodes of the right sub
 * tree greater than the parent node
 */
bool isBinarySearchTree(TreeNode *root)
{
    return leftSubtreeIsBst(root->left, root->value) &&
           rightSubtreeIsBst(root->right, root->value);
}

bool leftSubtreeIsBst(TreeNode *leftSubtreeRoot, int value)
{
    if (leftSubtreeRoot == NULL)
        return true;
    if (leftSubtreeRoot->left == NULL && leftSubtreeRoot->right == NULL) {
        if (leftSubtreeRoot->value <= value)
            return true;
        else
            return false;
    }

    return leftSubtreeIsBst(leftSubtreeRoot->left, leftSubtreeRoot->value) &&
           rightSubtreeIsBst(leftSubtreeRoot->right, leftSubtreeRoot->value) &&
           leftSubtreeRoot->value <= value;
}

bool rightSubtreeIsBst(TreeNode *rightSubtreeRoot, int value)
{
    if (rightSubtreeRoot == NULL)
        return true;
    if (rightSubtreeRoot->right == NULL && rightSubtreeRoot->left == NULL) {
        if (rightSubtreeRoot->value > value)
            return true;
        else
            return false;
    }

    return leftSubtreeIsBst(rightSubtreeRoot->left, rightSubtreeRoot->value) &&
           rightSubtreeIsBst(rightSubtreeRoot->right,
                             rightSubtreeRoot->value) &&
           rightSubtreeRoot->value > value;
}

int main(int argc, char *argv[])
{
    TreeNode *a = new TreeNode;
    a->value = 100;
    TreeNode *b = new TreeNode;
    b->value = 90;
    TreeNode *c = new TreeNode;
    c->value = 170;
    a->left = b;
    a->right = c;

    TreeNode *d = new TreeNode;
    d->value = 80;
    TreeNode *e = new TreeNode;
    e->value = 92;
    b->left = d;
    b->right = e;

    TreeNode *f = new TreeNode;
    f->value = 160;
    TreeNode *g = new TreeNode;
    g->value = 173;
    c->left = f;
    c->right = g;

    TreeNode *h = new TreeNode;
    h->value = 76;
    TreeNode *i = new TreeNode;
    i->value = 87;
    d->left = h;
    d->right = i;

    TreeNode *j = new TreeNode;
    j->value = 153;
    TreeNode *k = new TreeNode;
    k->value = 169;
    f->left = j;
    f->right = k;

    TreeNode *l = new TreeNode;
    l->value = 171;
    TreeNode *m = new TreeNode;
    m->value = 182;
    g->left = l;
    g->right = m;

    TreeNode *n = new TreeNode;
    n->value = 85;
    TreeNode *o = new TreeNode;
    o->value = 89;
    i->left = n;
    i->right = o;

    h->left = h->right = NULL;
    n->left = n->right = NULL;
    o->left = o->right = NULL;
    j->left = j->right = NULL;
    k->left = k->right = NULL;
    l->left = l->right = NULL;
    m->left = m->right = NULL;

    std::cout << (isBinarySearchTree(a) ? "true" : "false") << "\n";
}
