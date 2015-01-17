#include "tree.h"

enum TreeType
{
    MinTree = 1,
    MaxTree = 2,
    Unbalance = 4
};

int check(Node* root)
{
    int ret = MinTree | MaxTree;
    if (root->left != nullptr)
    {
        int lret = check(root->left);
        if (lret & Unbalance)
            return lret;
        if (root->left->value < root->value && (lret & MinTree) && (ret & MinTree))
            ret = MinTree;
        else if (root->left->value > root->value && (lret & MaxTree) && (ret & MaxTree))
            ret = MaxTree;
        else
            ret = Unbalance;
    }
    if (root->right != nullptr)
    {
        int rret = check(root->right);
        if (rret & Unbalance)
            return rret;
        if (root->right->value > root->value && (rret & MinTree) && (ret & MinTree))
            ret = MinTree;
        else if (root->right->value < root->value && (rret & MaxTree) && (ret & MaxTree))
            ret = MaxTree;
        else
            ret = Unbalance;       
    }
    return ret;
}

int main()
{
    Node* root = Node::createTree();
    int ret = check(root);
    switch (ret)
    {
    case MinTree:
        cout << "ascending search tree" << endl;
        break;
    case MaxTree:
        cout << "decending search tree" << endl;
        break;
    case Unbalance:
        cout << "unbalance" << endl;
        break;
    }
    return 0;
}