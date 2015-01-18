#include <iostream>
#include <string>
using namespace std;


string longestPalindrome(string s)
{
    if (s.size() == 1)
        return s;
    bool check[1001][1000];
    for (size_t i = 0; i < s.size(); i++)
    {
        check[1][i] = true;
        check[0][i] = true;
    }
    for (size_t i = 2; i < s.size(); i++)
        for (size_t k = 0; k < s.size(); k++)
            check[i][k] = false;
    int longest = 1;
    string ret; 
    for (size_t i = 2; i <= s.size(); i++)
    {
        for (size_t k = 0; k < s.size() - i + 1; k++)
        {
            if (check[i - 2][k + 1] && s[k] == s[k + i - 1])
            {
                check[i][k] = true;
                if (i > longest)
                {
                    longest = i;
                    ret = s.substr(k, i);
                }
            }
        }
    }
    return ret;
}

int main()
{
    string s = "aaabaaaa";
    cout << longestPalindrome(s) << endl;
    return 0;

}