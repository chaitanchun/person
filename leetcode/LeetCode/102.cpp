#include <iostream>
#include <vector>
#include <queue>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) 
    {
        vector<vector<int>> ret;
        queue<pair<TreeNode*, int>> q;
        if (root != NULL)
            q.push(make_pair(root, 0));
        while (q.size() > 0)
        {
            if (ret.size() == q.front().second)
                ret.push_back(vector<int>());
            ret[q.front().second].push_back(q.front().first->val);
            if (q.front().first->left != NULL)
                q.push(make_pair(q.front().first->left, q.front().second + 1));
            if (q.front().first->right != NULL)
                q.push(make_pair(q.front().first->right, q.front().second + 1));
            q.pop(); 
        }
        return ret;
    }
};

int main()
{
    return 0;
}