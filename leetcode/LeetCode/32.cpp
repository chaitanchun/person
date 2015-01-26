#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestValidParentheses(string s) 
{
    int ret = 0;
    vector<int> sta;
    sta.push_back(-1);
    int num = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            num++;
            sta.push_back(i);
        }
        else
        {
            if (sta.size() == 1)
            {
                if (num > ret)
                    ret = num;
                num = 0;
                sta.pop_back();
                sta.push_back(i);
            }
            else
            {
                num++;
                sta.pop_back();
            }
        }
    }
    if (sta.size() > 1)
    {
        sta.push_back(s.length());
        for (size_t i = 0; i < sta.size() - 1; i++)
        {
            if (sta[i + 1] - sta[i] - 1 > ret)
                ret = sta[i + 1] - sta[i] - 1;
        }
    }
    else
    {
        if (num > ret)
            ret = num;
    }
    return ret;
}

int main()
{
    int ret = longestValidParentheses("(()");
    return 0;
}