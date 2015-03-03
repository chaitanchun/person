#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) 
    {
        ListNode* ret = new ListNode(0);
        ListNode* cur = ret;
        n = n - m + 1;
        while (--m)
        {
            cur->next = head;
            head = head->next;
            cur = cur->next;
        }
        ListNode* next = NULL;
        ListNode* end = NULL;
        while (n--)
        {
            if (next == NULL)
                end = head;
            cur->next = head;
            head = head->next;
            cur->next->next = next;
            next = cur->next;
        }
        end->next = head;
        return ret->next;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    Solution s;
    head = s.reverseBetween(head, 2, 4);
    return 0;
}