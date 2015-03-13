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
    bool isValidBST(TreeNode *root) {

    }
private:
    bool isValid(TreeNode* root, int& min, int& max)
    {
        if (root == NULL)
            return true;
        bool ret = false;
        int lmin, lmax;
        int rmin, rmax;
        ret = ret || isValid(root->left, lmin, lmax);
        if (!ret)
            return ret;
        if (root->left != NULL && root->val <= lmax)
            return false;

        ret = ret || isValid(root->right, rmin, rmax);
        if ()


        return ret;
    }
};

int main()
{
    return 0;
}