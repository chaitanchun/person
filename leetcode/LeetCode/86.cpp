#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode* f = new ListNode(0);
        ListNode* ff = f;
        ListNode* s = new ListNode(0);
        ListNode* ss = s;
        while (head != NULL)
        {
            if (head->val < x)
            {
                f->next = head;
                f = f->next;
            }
            else
            {
                s->next = head;
                s = s->next;
            }
            head = head->next;
        }
        f->next = ss->next;
        s->next = NULL;
        return ff->next;
    }

};