#include <iostream>
using namespace std;

#define N 10

class Node
{
public:
    Node();
    ~Node();
    Node* next;
    int value;
};

Node::Node()
{
    next = nullptr;
    value = 0;
}

Node::~Node()
{
}

Node* createLinkedList()
{
    Node* head = new Node();
    Node* it = head;
    for (size_t i = 0; i < N; i++)
    {
        it->next = new Node();
        it = it->next;
        it->value = i + 1;
    }
    it->next = nullptr;
    return head;
}

Node* createNum1()
{
    Node* head = new Node();
    Node* it = head;
    it->value = 6;
    it->next = new Node();
    it = it->next;
    it->value = 1;
    it->next = new Node();
    it = it->next;
    it->value = 7;
    it->next = new Node();
    it = it->next;
    it->value = 1;
    it->next = new Node();
    it = it->next;
    it->value = 6;
    it->next = nullptr;
    return head;
}

Node* createNum2()
{
    Node* head = new Node();
    Node* it = head;
    it->value = 2;
    it->next = new Node();
    it = it->next;
    it->value = 9;
    it->next = new Node();
    it = it->next;
    it->value = 9;
    it->next = new Node();
    it = it->next;
    it->value = 2;
    it->next = nullptr;
    return head;
}

Node* createNum3()
{
    Node* head = new Node();
    Node* it = head;
    it->value = 6;
    it->next = new Node();
    it = it->next;
    it->value = 1;
    it->next = new Node();
    it = it->next;
    it->value = 7;
    it->next = nullptr;
    return head;
}

Node* createNum4()
{
    Node* head = new Node();
    Node* it = head;
    it->value = 2;
    it->next = new Node();
    it = it->next;
    it->value = 9;
    it->next = new Node();
    it = it->next;
    it->value = 5;
    it->next = new Node();
    it = it->next;
    it->value = 5;
    it->next = nullptr;
    return head;
}

void printList(Node* head)
{
    while (head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}