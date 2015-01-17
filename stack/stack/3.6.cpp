#include <stack>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    stack<int> st;
    stack<int> temp;
    for (size_t i = 0; i < 10; i++)
        st.push(rand() % 100);
    while (st.size() != 0)
    {
        int cur = st.top();
        st.pop();
        while (temp.size() != 0 && temp.top() > cur)
        {
            st.push(temp.top());
            temp.pop();
        }
        temp.push(cur);
        while (st.size() != 0 && st.top() >= temp.top())
        {
            temp.push(st.top());
            st.pop();
        }
    }
    int num = temp.size();
    for (size_t i = 0; i < num; i++)
    {
        cout << temp.top() <<" ";
        temp.pop();
    }
    cout << endl;
    return 0;
}