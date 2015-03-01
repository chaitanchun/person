#include <iostream>

using namespace std;

int numDecodings(string s) 
{
    if (s.length() == 0)
        return 0;

    int ret = s[0] == '0' ? 0 : 1;
    int pre = ret;
    for (size_t i = 1; i < s.length(); i++)
    {
        if (s[i] != '0' && (s[i - 1] == '2' && s[i] <= '6' || s[i - 1] == '1'))
        {
            int temp = pre;
            pre = ret;
            ret += temp;
        }
        else
        {
            if (s[i] == '0')
            {
                if(s[i - 1] != '1' && s[i - 1] != '2')
                    return 0;
                else
                {
                    if (ret != pre)
                        ret = pre;
                }
            }
            else
                pre = ret;
        }
    }
    return ret;
}

int main()
{
    cout << numDecodings("110") << endl;
    return 0;
}