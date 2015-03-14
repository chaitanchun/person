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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) 
    {
        if (preorder.size() == 0)
            return NULL;
        porder = preorder;
        iorder = inorder;
        return build(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(int pstart, int pend, int istart, int iend)
    {
        if (pstart > pend)
            return NULL;
        TreeNode* root = new TreeNode(porder[pstart]);
        vector<int>::iterator it = find(iorder.begin() + istart, iorder.begin() + iend + 1, porder[pstart]);
        int lnum = it - (iorder.begin() + istart);
        int rnum = iend - istart - lnum;
        root->left = build(pstart + 1, pstart + 1 + lnum - 1, istart, istart + lnum - 1);
        root->right = build(pstart + 1 + lnum, pend, istart + lnum + 1, iend);
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