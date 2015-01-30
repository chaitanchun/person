#include <iostream>
#include <string>
#include <stack>
using namespace std;

string count(string n)
{
    string ret;
    int index = 1;
    int num = 1;
    for (size_t i = 1; i < n.size(); i++)
    {
        if (n[i] != n[i - 1])
        {
            ret.push_back('0' + num);
            ret.push_back(n[i - 1]);
            num = 1;
        }
        else
        {
            num++;
        }
    }
    if (num > 0)
    {
        ret.push_back('0' + num);
        ret.push_back(n.back());
    }
    return ret;
}

string countAndSay(int n)
{
    string ret = "1";
    for (size_t i = 1; i < n; i++)
        ret = count(ret);
    return ret;
}

int main()
{
    cout << countAndSay(1) << endl;
    cout << countAndSay(2) << endl;
    cout << countAndSay(3) << endl;
    cout << countAndSay(4) << endl;
    cout << countAndSay(5) << endl;
    return 0;
}