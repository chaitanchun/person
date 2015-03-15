#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
            else
                return NULL;
            slow = slow->next;
            if (slow == fast)   
            {
                fast = head;
                while (fast != NULL)
                {
                    if (fast == slow)
                        return fast;
                    fast = fast->next;
                    slow = slow->next;
                }
            }
        }
        return NULL;
    }
};

int main()
{
    return 0;
}