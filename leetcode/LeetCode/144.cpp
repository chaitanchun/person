#include <iostream>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode *root) 
    {
        vector<int> ret;
        stack<TreeNode*> sta;
        TreeNode* node = root;
        while (node != NULL)
        {
            ret.push_back(node->val);
            if (node->left != NULL)
            {
                if (node->right != NULL)
                    sta.push(node->right);
                node = node->left;
            }
            else if (node->right != NULL)
            {
                node = node->right;
            }
            else
            {
                if (sta.size() > 0)
                {
                    node = sta.top();
                    sta.pop();
                }
                else
                    node = NULL;
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    vector<int> ret = s.preorderTraversal(root);
    return 0;
}