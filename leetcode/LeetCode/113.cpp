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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if (root != NULL)
            hasSum(root, sum);
        return ret;
    }
private:
    void hasSum(TreeNode* root, int sum)
    {
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if (sum - root->val == 0)
            {
                vector<int> temp = path;
                ret.push_back(temp);
            }
        }
        else
        {
            if (root->left != NULL)
                hasSum(root->left, sum - root->val);
            if (root->right != NULL)
                hasSum(root->right, sum - root->val);
        }
        path.pop_back();
    }
    vector<vector<int>> ret;
    vector<int> path;
};


int main()
{
    return 0;
}