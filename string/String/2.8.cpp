#include "Node.h"
#include <stack>

bool check(Node* head)
{
    Node* fasterRunner = head;
    Node* slowerRunner = head;
    stack<int> firstPart;
    while (fasterRunner != nullptr && fasterRunner->next != nullptr)
    {
        firstPart.push(slowerRunner->value);
        fasterRunner = fasterRunner->next->next;
        slowerRunner = slowerRunner->next;
    }
    if (fasterRunner != nullptr)
        slowerRunner = slowerRunner->next;
    while (firstPart.size() != 0 && slowerRunner != nullptr)
    {
        if (firstPart.top() != slowerRunner->value)
            return false;
        else
        {
            firstPart.pop();
            slowerRunner = slowerRunner->next;
        }
    }
    return true;
}

int main()
{
    cout << check(createNum1()) << endl;
    cout << check(createNum2()) << endl;
    cout << check(createNum3()) << endl;
    cout << check(createNum4()) << endl;
    return 0;
}