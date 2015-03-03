#include <iostream>
#include <algorithm>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    bool isBalanced(TreeNode *root) 
    {
        return balanced(root) == -1 ? false : true;
    }
private:
    int balanced(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int hl = balanced(root->left);
        if (hl == -1)
            return -1;
        int hr = balanced(root->right);
        if (hr == -1)
            return -1;
        if (abs(hl - hr) > 1)
            return -1;
        else
            return max(hl, hr) + 1;
    }
};
int main()
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    bool ret = s.isBalanced(root);
    return 0;

}