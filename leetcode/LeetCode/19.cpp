#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* fp = head;
        ListNode* sp = head;
        ListNode* tp = head;
        for (size_t i = 0; i < n; i++)
            fp = fp->next;

        if (fp == NULL)
        {
            head = head->next;
        }
        else{
            while (fp != NULL)
            {
                fp = fp->next;
                tp = sp;
                sp = sp->next;
            }
            tp->next = sp->next;
        }
        return head;
    }
};