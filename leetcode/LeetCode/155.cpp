#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

class MinStack {

    stack<int> data;
    stack<int> min;

public:

    void push(int x) {

        // If empty
        if (min.empty()) {
            data.push(x);
            min.push(x);
            return;
        }

        // Not empty
        data.push(x);

        if (x <= min.top())
            min.push(x);

    }

    void pop() {

        if (!min.empty()) {
            if (data.top() == min.top())
                min.pop();
            data.pop();
        }
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return min.top();
    }
};

int main()
{
    MinStack sta;
    sta.push(-3);
    cout << sta.top() <<"  "<< sta.getMin() << endl;
    sta.push(-4);
    sta.push(3);
    sta.push(2);
    cout << sta.top() <<"  "<< sta.getMin() << endl;
    sta.pop();
    cout << sta.top() <<"  "<< sta.getMin() << endl;
    sta.push(9);
    cout << sta.top() <<"  "<< sta.getMin() << endl;
    sta.pop();
    sta.pop();
    cout << sta.top() <<"  "<< sta.getMin() << endl;
    return 0;
}