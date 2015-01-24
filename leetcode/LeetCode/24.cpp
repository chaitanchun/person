#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head)
{
    ListNode* ret = NULL;
    ListNode* f = head;
    ListNode* s;
    ListNode* p = NULL;
    while (f != NULL)
    {
        if (f->next == NULL)
        {
            if (ret != NULL)
                p->next = f;
            else
                ret = head;
            break;
        }
        s = f->next->next;
        if (ret == NULL)
        {
            ret = f->next;
            ret->next = f;
        }
        else
        {
            p->next = f->next;
            p->next->next = f;
        }
        p = f;
        p->next = NULL;
        f = s;
    }
    return ret;
}

int main()
{
    ListNode* l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);
    l->next->next->next = new ListNode(4);
    l = swapPairs(l);
    return 0;
}