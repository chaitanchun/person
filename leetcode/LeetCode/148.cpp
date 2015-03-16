
class Solution {
public:
    ListNode *sortList(ListNode *head) {

        ListNode *head2;
        if (!head || !head->next)
        {// if the list is empty or only has one node, just return
            return head;
        }
        else
        {// split the list by half, sort each of them and merge the two half lists
            head2 = splitList(head);
            return mergeList(sortList(head), sortList(head2));
        }
    }

    // split the list (with length >= 2) in half, and return the head of the second half list
    ListNode *splitList(ListNode *head) {
        ListNode *fastP, *slowP, *newHead;
        fastP = head->next->next;
        slowP = head;
        while (fastP && fastP->next)
        {
            fastP = fastP->next->next;
            slowP = slowP->next;
        }
        newHead = slowP->next;
        slowP->next = NULL;

        return newHead;
    }

    // merge two lists, 
    ListNode *mergeList(ListNode *head1, ListNode *head2) {

        ListNode *newHead = head1, *pNode;

        if (!head2)
        {
            return head1;
        }
        else if (!head1)
        {
            return head2;
        }
        else
        {// both list1 and list2 are non-empty
            if (head1->val > head2->val)
            {
                newHead = head2;
                head2 = head1;
                head1 = newHead;
            }
            while (head2)
            {
                while (head1->next && (head1->next)->val <= head2->val)
                {
                    head1 = head1->next;
                }
                pNode = head1->next;
                head1->next = head2;
                head2 = pNode;
            }// while
            return newHead;
        }// else
    }

};