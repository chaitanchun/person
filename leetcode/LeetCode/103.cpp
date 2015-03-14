#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        queue<pair<TreeNode*, int>> q;
        if (root != NULL)
            q.push(make_pair(root, 0));
        while (q.size() > 0)
        {
            if (ret.size() == q.front().second)
            {
                if (ret.size() > 0 && ret.size() % 2 == 0)
                    reverse(ret.back().begin(), ret.back().end());
                ret.push_back(vector<int>());
            }
            ret[q.front().second].push_back(q.front().first->val);
            if (q.front().first->left != NULL)
                q.push(make_pair(q.front().first->left, q.front().second + 1));
            if (q.front().first->right != NULL)
                q.push(make_pair(q.front().first->right, q.front().second + 1));
            q.pop();
        }
        if (ret.size() > 0 && ret.size() % 2 == 0)
            reverse(ret.back().begin(), ret.back().end());
        return ret;
    }
};

int main()
{
    return 0;
}