#include <iostream>
#include <string>

#include <vector>
using namespace std; 

class Solution {
public:
    vector<string> restoreIpAddresses(string s) 
    {
            findip(4, s);
        return ret;
    }
private:
    void findip(int num, string s)
    {
        if (num == 0)
        {
            if (s.length() == 0)
                ret.push_back(cur.substr(1));
            return;
        }
        for (size_t i = 1; i <= 3; i++)
        {
            if (s.length() >= i)
            {
                int n = stoi(s.substr(0, i));
                if (n <= 255)
                {
                    cur.push_back('.');
                    cur.append(s.substr(0, i));
                    findip(num - 1, s.substr(i));
                    cur = cur.substr(0, cur.length() - i - 1);
                }
                if (n == 0)
                    break;
            }
            else
                break;
        }
    }
private:
    vector<string> ret;
    string cur;
};

int main()
{
    Solution s;
    vector<string> ret = s.restoreIpAddresses("010010");
    return 0;
}