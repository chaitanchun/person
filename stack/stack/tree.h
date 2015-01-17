#include <iostream>
using namespace std;

class Node
{
public:
    Node()
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
    Node(int v)
    {
        Node();
        value = v;
    }
    Node* left;
    Node* right;
    Node* parent;
    int value;

    static Node* createTree()
    {
        Node* top = new Node(3);
        top->left = new Node(1);
        top->left->parent = top;
        top->right = new Node(5);
        top->right->parent = top;
        top->left->left = new Node(0);
        top->left->left->parent = top->left;
        top->left->right = new Node(2);
        top->left->right->parent = top->left;
        top->right->left = new Node(4);
        top->right->left->parent = top->right;
        top->right->right = new Node(6);
        top->right->right->parent = top->right;
        return top;
    }
};