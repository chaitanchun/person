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
     void recoverTree(TreeNode *root) {
         TreeNode *cur, *pre, *node1, *node2;  // node1, node2: Record 2 near nodes
         TreeNode *first, *second;  // Record 2 swapping nodes
         node1 = node2 = first = NULL;
         cur = root;
         while (cur) {
             if (cur->left == NULL) {
                 if (node1 == NULL) node1 = cur;
                 else if (node2 == NULL) node2 = cur;
                 else { node1 = node2; node2 = cur; }
                 cur = cur->right;
             }
             else {
                 pre = cur->left;
                 while (pre->right && pre->right != cur) pre = pre->right;
                 if (pre->right == NULL) {
                     pre->right = cur;
                     cur = cur->left;
                     continue;
                 }
                 else {
                     pre->right = NULL;
                     if (node2 == NULL) node2 = cur;
                     else { node1 = node2; node2 = cur; }
                     cur = cur->right;
                 }
             }
             if (node1 && node2 && node1->val > node2->val) {

                 if (first == NULL)  first = node1;
                 second = node2;
             }
         }
         /* already learn that there exist 2 nodes swapped.*/
         int t = first->val;
         first->val = second->val;
         second->val = t;
     }
 };

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(2);
    root->right = new TreeNode(1);
    s.recoverTree(root);
    return 0;
}