#include "Node.h"

bool checkLoop(Node* head)
{
    Node* fasterRunner = head;
    Node* slowerRunner = head;
    while (fasterRunner != nullptr && fasterRunner->next != nullptr)
    {
        fasterRunner = fasterRunner->next->next;
        slowerRunner = slowerRunner->next;
        if (slowerRunner == fasterRunner)
            return true;
    }
    return false;
}

int getLoopSize(Node* head)
{
    Node* fasterRunner = head;
    Node* slowerRunner = head;
    while (true)
    {
        fasterRunner = fasterRunner->next->next;
        slowerRunner = slowerRunner->next;
        if (slowerRunner == fasterRunner)
            break;
    }
    int len = 0;
    while (true)
    {
        len++;
        fasterRunner = fasterRunner->next->next;
        slowerRunner = slowerRunner->next;
        if (slowerRunner == fasterRunner)
            break;
    }
    return len;
}


Node* findLoopStart(Node* head)
{
    Node* fasterRunner = head;
    Node* slowerRunner = head;
    while (true)
    {
        fasterRunner = fasterRunner->next->next;
        slowerRunner = slowerRunner->next;
        if (slowerRunner == fasterRunner)
            break;
    }
    slowerRunner = head;
    while (slowerRunner != fasterRunner)
    {
        slowerRunner = slowerRunner->next;
        fasterRunner = fasterRunner->next;
    }
    return fasterRunner;
}