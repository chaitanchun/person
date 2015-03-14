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
    void flatten(TreeNode *root) 
    {
        if (root == NULL)
            return;
        TreeNode* end;
        dfs(root, end);
    }
private:
    void dfs(TreeNode* root, TreeNode* &end)
    {
        end = root;
        TreeNode* tempRight = root->right;
        if (root->left != NULL)
        {
            TreeNode* leftEnd;
            dfs(root->left, leftEnd);
            root->right = root->left;
            end = leftEnd;
            root->left = NULL;
        }
        if (tempRight != NULL)
        {
            TreeNode* rightEnd;
            dfs(tempRight, rightEnd);
            end->right = tempRight;
            end = rightEnd;
        }
    }
};
int main()
{
    return 0;
}