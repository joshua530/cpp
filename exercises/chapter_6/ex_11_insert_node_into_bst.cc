#include <iostream>

struct TreeNode {
    int value;
    std::string name;
    TreeNode *left;
    TreeNode *right;
};

void insertNode(TreeNode *&current, int toInsert)
{
    if (current == NULL) {
        TreeNode *newNode = new TreeNode;
        newNode->value = toInsert;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->name = "new node";
        current = newNode;
    } else if (toInsert < current->value) {
        insertNode(current->left, toInsert);
    } else {
        insertNode(current->right, toInsert);
    }
}

void printTree(TreeNode *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;

    if (root->left != NULL)
        std::cout << root->name << ".left=" << root->left->name << ";\n";
    if (root->right != NULL)
        std::cout << root->name << ".right=" << root->right->name << ";\n";

    printTree(root->left);
    printTree(root->right);
}

int main(int argc, char *argv[])
{
    TreeNode *a = new TreeNode;
    a->name = "a";
    a->value = 100;
    TreeNode *b = new TreeNode;
    b->name = "b";
    b->value = 90;
    TreeNode *c = new TreeNode;
    c->name = "c";
    c->value = 170;
    a->left = b;
    a->right = c;

    TreeNode *d = new TreeNode;
    d->name = "d";
    d->value = 80;
    TreeNode *e = new TreeNode;
    e->name = "e";
    e->value = 92;
    b->left = d;
    b->right = e;

    TreeNode *f = new TreeNode;
    f->name = "f";
    f->value = 160;
    TreeNode *g = new TreeNode;
    g->name = "g";
    g->value = 173;
    c->left = f;
    c->right = g;

    TreeNode *h = new TreeNode;
    h->name = "h";
    h->value = 76;
    TreeNode *i = new TreeNode;
    i->name = "i";
    i->value = 87;
    d->left = h;
    d->right = i;

    TreeNode *j = new TreeNode;
    j->name = "j";
    j->value = 153;
    TreeNode *k = new TreeNode;
    k->name = "k";
    k->value = 169;
    f->left = j;
    f->right = k;

    TreeNode *l = new TreeNode;
    l->name = "l";
    l->value = 171;
    TreeNode *m = new TreeNode;
    m->name = "m";
    m->value = 182;
    g->left = l;
    g->right = m;

    TreeNode *n = new TreeNode;
    n->name = "n";
    n->value = 85;
    TreeNode *o = new TreeNode;
    o->name = "o";
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
    printTree(a);

    insertNode(a, 22);
    printTree(a);
}
