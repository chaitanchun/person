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
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<TreeNode*>> dp;
        vector<TreeNode*> temp;
        temp.push_back(NULL);
        dp.push_back(temp);
        vector<TreeNode*> temp1;
        temp1.push_back(new TreeNode(0));
        dp.push_back(temp1);
        for (int i = 2; i <= n; i++)
        {
            vector<TreeNode*> cur;
            for (int j = 1; j <= i; j++)
            {
                // j -1 , i - j
                for (int k = 0; k < dp[j - 1].size(); k++)
                {
                    for (int m = 0; m < dp[i - j].size(); m++)
                    {
                        cur.push_back(new TreeNode(0));
                        cur.back()->left = cloneTree(dp[j - 1][k]);
                        cur.back()->right = cloneTree(dp[i - j][m]);
                    }
                }
            }  
            dp.push_back(cur);
        }
        for (int i = 0; i < dp[n].size(); i++)
        {
            mValue = 1;
            fillValue(dp[n][i]);
        }
        return dp[n];

    }
private:
    void fillValue(TreeNode* root)
    {
        if (root == NULL)
            return;
        fillValue(root->left);
        root->val = mValue++;
        fillValue(root->right);
    }
    TreeNode* cloneTree(TreeNode* root)
    {
        if (root == NULL)
            return NULL;
        TreeNode* ret = new TreeNode(root->val);
        ret->left = cloneTree(root->left);
        ret->right = cloneTree(root->right);
        return ret;
    }

private:
    int mValue;
};

int main()
{
    vector<TreeNode*> ret;
    Solution s;
    ret = s.generateTrees(3);
    return 0;
}