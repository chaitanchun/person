#include "tree.h"
#include <list>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    //create tree
    Node* top = new Node(0);
    top->left = new Node(1);
    top->right = new Node(2);
    top->left->left = new Node(3);
    top->left->right = new Node(4);
    top->right->left = new Node(5);
    top->right->right = new Node(6);
    queue<Node*> que;
    vector<list<Node*>> ret = vector<list<Node*>>();
    que.push(top);
    queue<int> levels;
    levels.push(0);
    while (que.size() > 0)
    {
        Node* cur = que.front();
        if (ret.size() == levels.front())
            ret.push_back(list<Node*>());
        ret[levels.front()].push_back(cur);
        if (cur->left != nullptr)
        {
            que.push(cur->left);
            levels.push(levels.front() + 1);
        }
        if (cur->right != nullptr)
        {
            que.push(cur->right);
            levels.push(levels.front() + 1);
        }
        que.pop();
        levels.pop();
    }
    return 0;
}