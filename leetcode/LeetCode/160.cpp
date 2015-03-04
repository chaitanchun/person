#include <iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        int na = 0;
        ListNode* pa = headA;
        while (pa != NULL)
        {
            na++;
            pa = pa->next;
        }
        int nb = 0;
        ListNode* pb = headB;
        while (pb != NULL)
        {
            nb++;
            pb = pb->next;
        }
        pa = headA;
        pb = headB;
        if (na > nb)
        {
            int num = na - nb;
            while (num--)
                pa = pa->next;
        }
        else if (nb > na)
        {
            int num = nb - na;
            while (num--)
                pb = pb->next;
        }
        while (pa != NULL)
        {
            if (pa == pb)
                return pa;
            else
            {
                pa = pa->next;
                pb = pb->next;
            }
        }
        return NULL;
    }
};

int main()
{
    return 0;
}