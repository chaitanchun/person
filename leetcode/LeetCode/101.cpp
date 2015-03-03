#include <iostream>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isSymmetric(TreeNode *root) 
    {
        return root == NULL ? true : isMirror(root->left, root->right);
    }
private:
    bool isMirror(TreeNode* p, TreeNode* q)
    {
        if (p == NULL || q == NULL)
        {
            if (p == NULL && q == NULL)
                return true;
            else
                return false;
        }
        else if (p->val == q->val)
        {
            return isMirror(p->right, q->left) && isMirror(p->left, q->right);
        }
        else
            return false;
    }
};

int main()
{
    return 0;
}