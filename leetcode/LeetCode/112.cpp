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
    bool hasPathSum(TreeNode *root, int sum) 
    {
        if (root == NULL)
            return false;
        else
            return hasSum(root, sum);
    }
private:
    bool hasSum(TreeNode* root, int sum)
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (sum - root->val == 0)
                return true;
            else
                return false;
        }
        bool ret = false;
        if (root->left != NULL)
            ret = ret || hasSum(root->left, sum - root->val);
        if (ret)
            return ret;
        if (root->right != NULL)
            ret = ret || hasSum(root->right, sum - root->val);
        return ret;
    }
};
int main()
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    bool ret = s.hasPathSum(root, 1);
    return 0;
}