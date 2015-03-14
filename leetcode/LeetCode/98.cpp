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
    bool isValidBST(TreeNode *root) 
    {
        int min, max;
        return root == NULL ? true : isValid(root, min, max);
    }
private:
    bool isValid(TreeNode* root, int& min, int& max)
    {
        bool ret = true;
        int lmin = root->val;
        int lmax = root->val;
        int rmin = root->val;
        int rmax = root->val;
        if (root->left != NULL)
        {
            ret = isValid(root->left, lmin, lmax);
            if (!ret || root->left != NULL && root->val <= lmax)
                return false;
        }

        if (root->right != NULL)
        {
            ret = isValid(root->right, rmin, rmax);
            if (!ret || root->right != NULL && root->val >= rmin)
                return false;
        }
        min = lmin;
        max = rmax;
        return ret;
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(-1);
    bool ret = s.isValidBST(root);
    return 0;
}