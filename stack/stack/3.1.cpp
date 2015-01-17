#include <stack>
#include <iostream>
using namespace std;

class MyStack
{
public:
    void push(int value);
    int pop();
    int min();
private:
    stack<int> st;
    stack<int> minValue;
};

int MyStack::min()
{
    return minValue.top();
}

void MyStack::push(int value)
{
    st.push(value);
    if (value < minValue.top())
        minValue.push(value);
    else
        minValue.push(minValue.top());
}

int MyStack::pop()
{
    st.pop();
    minValue.pop();
}

int main()
{
    return 0;
}