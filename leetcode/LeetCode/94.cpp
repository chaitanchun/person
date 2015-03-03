#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) 
    {
        stack<TreeNode*> sta;
        vector<int> ret;
        while (root)
        {
            if (root->left != NULL)
            {
                sta.push(root);
                root = root->left;
            }
            else
            {
                ret.push_back(root->val);
                if (root->right != NULL)
                {
                    root = root->right;
                }
                else
                {
                    if (sta.size() == 0)
                        break;

                    do
                    {
                        ret.push_back(sta.top()->val);
                        root = sta.top()->right;
                        sta.pop();
                    } while (sta.size() > 0 && root == NULL);
                }
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> ret = s.inorderTraversal(root);
    return 0;
}
