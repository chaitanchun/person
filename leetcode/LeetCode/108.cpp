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
    TreeNode *sortedArrayToBST(vector<int> &num) 
    {
        if (num.size() == 0)
            return NULL;
        mNum = num;
        return buildTree(0, num.size() - 1);
    }
private:
    TreeNode* buildTree(int start, int end)
    {
        if (start > end)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode* ret = new TreeNode(mNum[mid]);
        ret->left = buildTree(start, mid - 1);
        ret->right = buildTree(mid + 1, end);
        return ret;
    }
private:
    int value = 0;
    vector<int> mNum;
};

int main()
{
    return 0;
}
