#include "Node.h"

int reverseFind(Node* head, int k)
{
    Node* ret = head;
    int count = 0;
    while (head != nullptr)
    {
        if (count == k)
            ret = ret->next;
        else
            count++;
        head = head->next;
    }
    return ret->value;
}

int main()
{
    Node* head = createLinkedList();
    cout << reverseFind(head, 2) << endl;
    cout << reverseFind(head, 6) << endl;
    return 0;
}