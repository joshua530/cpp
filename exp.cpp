#include "class_tree_recursion.cc"

int main(int argc, char const *argv[])
{
    BinaryTree::TreeNode *a = new BinaryTree::TreeNode;
    a->data = 2;
    BinaryTree::TreeNode *b = new BinaryTree::TreeNode;
    b->data = 7;
    BinaryTree::TreeNode *c = new BinaryTree::TreeNode;
    c->data = 5;

    a->left = b;
    a->right = c;

    BinaryTree::TreeNode *d = new BinaryTree::TreeNode;
    d->data = 2;
    d->left = NULL;
    d->right = NULL;

    BinaryTree::TreeNode *e = new BinaryTree::TreeNode;
    e->data = 10;
    e->left = NULL;
    e->right = NULL;

    b->left = d;
    b->right = e;

    BinaryTree::TreeNode *f = new BinaryTree::TreeNode;
    f->data = 16;
    BinaryTree::TreeNode *g = new BinaryTree::TreeNode;
    g->data = 9;

    c->left = f;
    c->right = g;

    BinaryTree::TreeNode *h = new BinaryTree::TreeNode;
    h->data = 5;
    h->left = NULL;
    h->right = NULL;

    BinaryTree::TreeNode *i = new BinaryTree::TreeNode;
    i->data = 11;
    i->left = NULL;
    i->right = NULL;

    f->left = h;
    f->right = i;

    BinaryTree::TreeNode *j = new BinaryTree::TreeNode;
    j->data = 4;
    j->left = NULL;
    j->right = NULL;

    g->left = j;
    g->right = NULL;

    BinaryTree tree(a);

    std::cout << tree.numLeaves() << "\n";
}
