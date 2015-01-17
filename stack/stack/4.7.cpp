#include "tree.h"

bool isChild(Node* root, Node* child)
{
    if (root == nullptr)
        return false;
    if (root == child)
        return true;
    else
    {
        if (isChild(root->left, child) || isChild(root->right, child))
            return true;
        else
            return false;
    }
}

Node* commonParent(Node* first, Node* second)
{
    Node* parent = first->parent;
    while (parent != nullptr)
    {
        if (isChild(parent, second))
        {
            break;
        }
        parent = parent->parent;
    }
    return parent;
}


int main()
{
    Node* root = Node::createTree();
    Node* ret = commonParent(root->left->right, root->right);
    cout << ret->value << endl;
    return 0;
}