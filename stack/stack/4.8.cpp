#include "tree.h"

int getHeight(Node* root)
{
    if (root == nullptr)
        return -1;

    int lHeight = getHeight(root->left);
    int rHeight = getHeight(root->right);
    return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
}

Node* T2;
int T2height;


bool equalTree(Node* first, Node* second)
{
    if (first == nullptr && second == nullptr)
        return true;
    else if (first == nullptr || second == nullptr)
        return false;
    else
    {
        if (first->value == second->value && equalTree(first->left, second->left)
            && equalTree(first->right, second->right))
            return true;
        else
            return false;
    }
}

bool hasChild(Node* root, int& height)
{
    if (root == nullptr)
    {
        height = -1;
        return false;
    }
    int lHeight, rHeight;
    if (hasChild(root->left, lHeight) || hasChild(root->right, rHeight))
    {
        return true;
    }
    else
    {
        height = lHeight > rHeight ? lHeight + 1; rHeight + 1;
        if (height == T2height)
        {
            if (equalTree(root, T2))
                return true;
        }
    }
    return false;
}

int main()
{
    T2height = getHeight(T2);

    return 0;
}