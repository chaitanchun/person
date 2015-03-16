#include <iostream>
#include <vector>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int sumNumbers(TreeNode *root) 
    {
        traversal(root);
        return ret;
    }
private:
    int num = 0;
    int ret = 0;
    void traversal(TreeNode* root)
    {
        if (root == NULL)
            return;
        num *= 10;
        num += root->val;
        traversal(root->left);
        traversal(root->right);
        if (root->left == NULL && root->right == NULL)
            ret += num;
        num /= 10;
    }
};

int main()
{
    return 0;
}