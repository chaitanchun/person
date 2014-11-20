#include "Node.h"

Node* partSort(Node* head, int x)
{
    Node* firstHead = nullptr;
    Node* firstTail = nullptr;
    Node* secondHead = nullptr;
    Node* secondTail = nullptr;
    while (head != nullptr)
    {
        if (head->value > x)
        {
            if (secondHead == nullptr)
            {
                secondHead = head;
                secondTail = head;
            }
            else
            {
                secondTail->next = head;
                secondTail = secondTail->next;
            }
        }
        else
        {
            if (firstHead == nullptr)
            {
                firstHead = head;
                firstTail = head;
            }
            else
            {
                firstTail->next = head;
                firstTail = firstTail->next;
            }
        }
        head = head->next;
    }
    head = secondHead;
    secondTail->next = firstHead;
    firstTail->next = nullptr;
    return head;
}

int main()
{
    Node* head = createLinkedList();
    printList(head);
    head = partSort(head, 5);
    printList(head);
    return 0;
}