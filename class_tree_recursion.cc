#include <iostream>

class BinaryTree {
public:
    struct TreeNode {
        int data;
        TreeNode *left;
        TreeNode *right;
    };
    typedef TreeNode *Tree;
    int numLeaves();
    BinaryTree(Tree root);

private:
    int numLeaves(TreeNode *node);
    Tree _rootNode;
};

BinaryTree::BinaryTree(Tree root)
{
    _rootNode = root;
}

// wrapper function
int BinaryTree::numLeaves()
{
    return numLeaves(_rootNode);
}

int BinaryTree::numLeaves(TreeNode *node)
{
    if (node == NULL)
        return 0;
    if (node->right == NULL && node->left == NULL)
        return 1;

    int leavesLeft = numLeaves(node->left);
    int leavesRight = numLeaves(node->right);
    return leavesLeft + leavesRight;
}
