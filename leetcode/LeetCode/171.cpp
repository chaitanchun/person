#include <iostream>

using namespace std;
class Solution {
public:
    int titleToNumber(string s) 
    {
        int base = 1;
        int ret = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            ret += (s[i] - 'A' + 1) * base;
            base *= 26;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    int ret = s.titleToNumber("A");
    return 0;
}