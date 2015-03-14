#include <iostream>
#include <vector>
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.size() == 0)
            return NULL;
        porder = postorder;
        iorder = inorder;
        return build(0, postorder.size() - 1, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(int pstart, int pend, int istart, int iend)
    {
        if (pstart > pend)
            return NULL;
        TreeNode* root = new TreeNode(porder[pend]);
        vector<int>::iterator it = find(iorder.begin() + istart, iorder.begin() + iend + 1, porder[pend]);
        int lnum = it - (iorder.begin() + istart);
        int rnum = iend - istart - lnum;
        root->left = build(pstart, pstart + lnum - 1, istart, istart + lnum - 1);
        root->right = build(pstart + lnum, pend - 1, istart + lnum + 1, iend);
        return root;
    }
    vector<int> porder;
    vector<int> iorder;
};

int main()
{
    Solution s;
    vector<int> a = { 1, 2 };
    vector<int> b = { 2, 1 };
    TreeNode* ret = s.buildTree(a, b);

    return 0;
}