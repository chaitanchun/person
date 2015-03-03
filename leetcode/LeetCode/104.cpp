#include <iostream>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    int maxDepth(TreeNode *root) 
    {
        traverse(0, root);
        return max;
    }
private:
    int max = 0;
    void traverse(int level, TreeNode* root)
    {
        if (root == NULL)
        {
            if (level > max)
                max = level;
            return;
        }
        traverse(level + 1, root->left);
        traverse(level + 1, root->right);
    }
};

int main()
{
    return 0;
}