#include "tree.h"
#include <stack>
using namespace std;

stack<int> path;
int sum = 0;

void searchPath(Node* root, int value)
{
    if (root == nullptr)
        return;
    searchPath(root->left);


    
}



int main()
{
    return 0;
}