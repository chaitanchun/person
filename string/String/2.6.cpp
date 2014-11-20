#include "Node.h"

Node* add(Node* first, Node* second)
{
    Node* ret = nullptr;
    Node* retTail = nullptr;
    int inc = 0;
    while (first != nullptr && second != nullptr)
    {
        if (ret == nullptr)
        {
            ret = new Node();
            retTail = ret;
            int sum = first->value + second->value;
            retTail->value = sum % 10;
            inc = sum / 10;
        }
        else
        {
            retTail->next = new Node();
            retTail = retTail->next;
            int sum = first->value + second->value + inc;
            retTail->value = sum % 10;
            inc = sum / 10;
        }
        first = first->next;
        second = second->next;
    }
    while (first != nullptr)
    {
        retTail->next = new Node();
        retTail = retTail->next;
        int sum = first->value + inc;
        retTail->value = sum % 10;
        inc = sum / 10;
        first = first->next;
    }
    while (second != nullptr)
    {
        retTail->next = new Node();
        retTail = retTail->next;
        int sum = second->value + inc;
        retTail->value = sum % 10;
        inc = sum / 10;
        second = second->next;
    }
    return ret;
}

Node * reverseList(Node* head)
{
    Node* tail = nullptr;
    while (head != nullptr)
    {
        Node* cur = head;
        head = head->next;
        cur->next = tail;
        tail = cur;
    }
    return tail;
}

int main()
{
    Node* first = createNum1();
    printList(first);
    Node* second = createNum2();
    printList(second);
    Node* sum = add(first, second);
    printList(sum);

    first = createNum3();
    printList(first);
    first = reverseList(first);
    printList(first);
    second = createNum4();
    printList(second);
    second = reverseList(second);
    printList(second);
    sum = add(first, second);
    printList(sum);
    return 0;
}

