#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode* ret = new ListNode(-1);
    ListNode* root = ret;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val <= l2->val)
        {
            ret->next = l1;
            l1 = l1->next;
            ret = ret->next;
        }
        else 
        {
            ret->next = l2;
            l2 = l2->next;
            ret = ret->next;
        }
    }
    while (l1 != NULL)
    {
        ret->next = l1;
        l1 = l1->next;
        ret = ret->next;
    }
    while (l2 != NULL)
    {
        ret->next = l2;
        l2 = l2->next;
        ret = ret->next;
    }
    return root->next;
}

int main()
{

    return 0;
}