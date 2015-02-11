#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode* start = new ListNode(0);
        ListNode* end = head;
        head = start;
        while (end != NULL)
        {
            if (end->next != NULL && end->val == end->next->val)
            {
                int cur = end->val;
                end = end->next->next;
                while (end != NULL && end->val == cur)
                    end = end->next;
            }
            else
            {
                start->next = end;
                start = end;
                end = end->next;
            }
        }
        start->next = NULL;
        return head->next;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    Solution s;
    head = s.deleteDuplicates(head);
    return 0;

}