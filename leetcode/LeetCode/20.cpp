#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> track; 
    for (size_t i = 0; i < s.length(); i++)
    {
        switch (s[i])
        {
        case '(':
        case '{':
        case '[':
            track.push(s[i]);
            break;
        case ')':
            if (track.size() > 0 && track.top() == '(')
                track.pop();
            else
                return false;
            break;
        case ']':
            if (track.size() > 0 && track.top() == '[')
                track.pop();
            else
                return false;
            break;
        case '}':
            if (track.size() > 0 && track.top() == '{')
                track.pop();
            else
                return false;
            break;
        }
    }
    return track.size() == 0 ? true : false;
}


int main()
{
    cout << isValid("]");
    return 0;
}