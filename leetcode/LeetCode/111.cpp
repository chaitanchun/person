#include <iostream>
#include <math.h>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    int minDepth(TreeNode *root) 
    {
        if (root == NULL)
            return 0;
        traverse(root, 1);
        return min;
    }
private:
    void traverse(TreeNode* root, int level)
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (level < min)
                min = level;
            return;
        }
        if (root->left != NULL)
            traverse(root->left, level + 1);
        if (root->right != NULL)
            traverse(root->right, level + 1);
    }
    int min = INT_MAX;
};

int main()
{
    return 0;
}