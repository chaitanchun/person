#include <iostream>
#include <string>
using namespace std;

string convert(string s, int nRows) 
{
    string ret = s;
    if (nRows == 1)
        return ret;
    int j = 0;
    int num = 2 * nRows - 2;
    for (size_t i = 0; i < nRows; i++)
    {
        size_t k = i;
        size_t m = num - i;
        int dou = true;
        if (m == i || m == num)
            dou = false;
        for (; k < s.size(); k += num, m += num)
        {
            ret[j++] = s[k];
            if (dou && m < s.size())
                ret[j++] = s[m];
        }
    }
    return ret;
}

int main()
{
    cout << convert("A", 1) << endl;
    return 0;
}