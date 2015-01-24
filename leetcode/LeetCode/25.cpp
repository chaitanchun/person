#include <iostream>
#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode* ret = new ListNode(0);
    ListNode* h = head;
    ListNode* t = ret;
    while (head != NULL)
    {
        size_t i;
        h = head;
        stack<ListNode*> reverse;
        for (i = 0; head != NULL && i < k; i++)
        {
            reverse.push(head);
            head = head->next;
        }
        if (i == k)
        {
            while (reverse.size() >  0)
            {
                t->next = reverse.top();
                reverse.pop();
                t = t->next;
            }
            t->next = NULL;
        }
        else
        {
            t->next = h;
        }
    }
    return ret->next;
}

int main()
{
    ListNode* l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l->next->next->next->next = new ListNode(5);
    ListNode* re = reverseKGroup(l, 2);
    ListNode* re2 = reverseKGroup(l, 3);
    return 0;
}