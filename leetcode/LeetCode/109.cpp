#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)
            return NULL;

        while (head != NULL)
        {
            num.push_back(head->val);
            head = head->next;
        }
        return buildTree(0, num.size() - 1);
    }
private:
    TreeNode* buildTree(int start, int end)
    {
        if (start > end)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode* ret = new TreeNode(num[mid]);
        ret->left = buildTree(start, mid - 1);
        ret->right = buildTree(mid + 1, end);
        return ret;
    }
private:
    vector<int> num;
};

int main()
{
    return 0;
}