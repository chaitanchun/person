#include <iostream>

using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) 
    {
        ListNode* start = head;
        ListNode* end = head;
        while (start != NULL)
        {
            end = end->next;
            while (end != NULL && end->val == start->val)
                end = end->next;
            start->next = end;
            start = end;
        }
        return head;
    }
};

int main()
{
    return 0;
}