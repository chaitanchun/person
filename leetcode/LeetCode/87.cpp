#include <iostream>
#include <vector>
#include <string>


using namespace std;

bool isScramble(string s1, string s2) 
{
    if (s1.length() != s2.length())
        return false;
    vector<vector<vector<bool>>> dp;
    vector<vector<bool>> init;
    for (size_t i = 0; i < s1.length(); i++)
    {
        vector<bool> equal;
        for (size_t k = 0; k < s2.length(); k++)
        {
            if (s1[i] == s2[k])
                equal.push_back(true);
            else
                equal.push_back(false);
        }
        init.push_back(equal);
    }
    dp.push_back(init);
    for (size_t i = 1; i < s1.length(); i++)
    {
        vector<vector<bool>> match;
        for (size_t k = 0; k < s1.length() - i; k++)
        {
            vector<bool> equal;
            for (size_t j = 0; j < s1.length() - i; j++)
            {
                bool cur = false;
                for (size_t m = 0; m < i; m++)
                {
                    cur = cur || (dp[m][k][j] && dp[i - m - 1][k + m + 1][j + m + 1]);
                    if (cur)
                        break;
                    cur = cur || (dp[m][k][j + i - m] && dp[i - m - 1][k + m + 1][j]);
                    if (cur)
                        break;
                }
                equal.push_back(cur);
            }
            match.push_back(equal);
        }
        dp.push_back(match);
    }
    return dp[s1.length() - 1][0][0];
}

int main()
{
    cout << isScramble("great", "rgeat") << endl;
    return 0;
}