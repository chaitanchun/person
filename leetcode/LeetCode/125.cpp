#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) 
    {
        int start = 0;
        int end = s.length() - 1;
        while (start < end)
        {
            if (!(s[start] <= 'Z' && s[start] >= 'A' || s[start] <= 'z' && s[start] >= 'a' || s[start] <= '9' && s[start] >= '0'))
            {
                start++;
                continue;
            }
            if (!(s[end] <= 'Z' && s[end] >= 'A' || s[end] <= 'z' && s[end] >= 'a' || s[end] <= '9' && s[end] >= '0'))
            {
                end--;
                continue;
            }
            if (s[start] <= 'Z' && s[start] >= 'A')
                s[start] = s[start] - ('Z' - 'z');
            if (s[end] <= 'Z' && s[end] >= 'A')
                s[end] = s[end] - ('Z' - 'z');
            if (s[start] == s[end])
            {
                start++;
                end--;
            }
            else
                return false;
        }
        return true;
    }
};

int main()
{
    return 0;

}