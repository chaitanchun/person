#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string addBinary(string a, string b) {
    string ret;
    int num = min(a.length(), b.length());
    int inc = 0;
    for (int i = 1; i <= num; i++)
    {
        int cur = inc + (a[a.size() - i] == '1' ? 1 : 0) + (b[b.size() - i] == '1' ? 1 : 0);
        inc = cur / 2;
        ret.push_back(cur % 2 == 1 ? '1' : '0');
    }
    if (b.size() > a.size())
        a = b;
    for (int i = num + 1; i <= a.size(); i++)
    {
        int cur = inc + (a[a.size() - i] == '1' ? 1 : 0);
        inc = cur / 2;
        ret.push_back(cur % 2 == 1 ? '1' : '0');
    }
    if (inc == 1)
        ret.push_back('1');
    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    cout << addBinary("11", "1") << endl;
    return 0;
}