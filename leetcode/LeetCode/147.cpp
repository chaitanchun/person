#include <iostream>
#include <math.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) 
    {
        ListNode* ret = new ListNode(INT_MIN);
        ListNode* cur = head;
        while (cur != NULL)
        {
            ListNode* index = ret;
            while (index->next != NULL && index->next->val <= cur->val)
                index = index->next;
            ListNode* temp = cur;
            cur = cur->next;
            temp->next = index->next;
            index->next = temp;
        }
        return ret->next;
    }
};

int main()
{
    Solution s;
    ListNode* head = new ListNode(1);
    head = s.insertionSortList(head);
    return 0;
}