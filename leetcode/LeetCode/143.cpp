#include <iostream>

using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    void reorderList(ListNode *head) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL)
        {
            if (fast->next == NULL || fast->next->next == NULL)
            {
                ListNode* temp = slow->next;
                slow->next = NULL;
                slow = temp;
            }
            else
                slow = slow->next;
            if (fast->next != NULL)
                fast = fast->next;
            else
                break;
            fast = fast->next;
        } 
        if (slow == head || slow == NULL)
            return;
        //slow
        fast = slow->next;
        slow->next = NULL;
        while (fast != NULL)
        {
            ListNode* temp = fast;
            fast = fast->next;
            temp->next = slow;
            slow = temp;
        }
        // 
        fast = head;
        while (slow != NULL)
        {
            ListNode* temp = fast->next;
            fast->next = slow;
            slow = slow->next;
            fast = fast->next;
            fast->next = temp;
            fast = fast->next;
        }
    }
};
int main()
{
    return 0;
}