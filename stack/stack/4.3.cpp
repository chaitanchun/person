#include "tree.h"
#include <vector>
using namespace std;
vector<int> arr;

Node* buildTree(int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = (start + end) / 2;
    Node* parent = new Node(arr[mid]);
    parent->left = buildTree(start, mid - 1);
    parent->right = buildTree(mid + 1, end);
    return parent;
}

int main()
{
    for (size_t i = 0; i < 5; i++)
    {
        arr.push_back(i);
    }
    Node* tree = buildTree(0, 4);
    return 0;
}