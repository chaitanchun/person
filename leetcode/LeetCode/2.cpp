#include <iostream>


using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* tail = NULL;
    ListNode* root = NULL;
    int inc = 0;
    while (l1 != NULL && l2 != NULL)
    {
        ListNode* newNode = new ListNode((l1->val + l2->val + inc) % 10);
        if (root == NULL)
            root = newNode;
        else
            tail->next = newNode;
        tail = newNode;
        inc = (l1->val + l2->val + inc) / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != NULL)
    {
        ListNode* newNode = new ListNode((l1->val + inc) % 10);
        if (root == NULL)
            root = newNode;
        else
            tail->next = newNode;
        tail = newNode;
        inc = (l1->val + inc) / 10;
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        ListNode* newNode = new ListNode((l2->val + inc) % 10);
        if (root == NULL)
            root = newNode;
        else
            tail->next = newNode;
        tail = newNode;
        inc = (l2->val + inc) / 10;
        l2 = l2->next;
    }
    // here
    if (inc > 0)
    {
        ListNode* newNode = new ListNode(inc);
        tail->next = newNode;
    }
    return root;
}

int main()
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(9);
    l2->next = new ListNode(9);
    ListNode* ret = addTwoNumbers(l1, l2);

    return 0;
}