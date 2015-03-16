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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        stack<TreeNode*> sta;
        TreeNode* node = root;
        while (node != NULL)
        {
            if (node->left != NULL)
            {
                sta.push(node);
                node = node->left;
                sta.top()->left = NULL;
            }
            else if (node->right != NULL)
            {
                sta.push(node);
                node = node->right;
                sta.top()->right = NULL;
            }
            else
            {
                ret.push_back(node->val);
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
    vector<int> ret = s.postorderTraversal(root);
    return 0;
}