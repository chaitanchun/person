#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    string convertToTitle(int n) 
    {
        string ret;
        while (--n / 26)
        {
            ret.push_back('A' + n % 26);
            n = n / 26;
        }
        ret.push_back('A' + n % 26);
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
int main()
{
    Solution s;
    string ret = s.convertToTitle(28);
    return 0;
}