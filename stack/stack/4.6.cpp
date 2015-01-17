#include "tree.h"

Node* getNext(Node* current)
{
    Node* ret;
    if (current->right != nullptr)
    {
        //find left
        ret = current->right;
        while(ret->left != nullptr)
            ret = ret->left;
    }
    else
    {
        ret = nullptr;
        Node* parent = current->parent;
        Node* child = current;
        while (parent != nullptr)
        {
            if (parent->left == child)
            {
                ret = parent;
                break;
            }
            child = parent;
            parent = parent->parent;
        }
    }
    return ret;

}

int main()
{
    Node* root = Node::createTree();
    root = root->left->right;
    Node* ret = getNext(root);
    if (ret == nullptr)
        cout << "no next" << endl;
    else
        cout << ret->value << endl;
    return 0;
}