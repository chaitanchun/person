#include "Node.h"
#include <unordered_set>

void removeDuple(Node* head)
{
    unordered_set<int> value; 
    Node* pre = head;
    value.insert(head->value);
    head = head->next;
    while (head != nullptr)
    {
        auto it = value.find(head->value);
        if (it == value.end())
        {
            value.insert(head->value);
            pre = head;
        }
        else
        {
            pre->next = head->next;
        }
        head = head->next;
    }
}

void removeDuple2(Node* head)
{

}

int main()
{
    
    return 0;
}