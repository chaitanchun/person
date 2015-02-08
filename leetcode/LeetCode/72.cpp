#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        vector<vector<int>> dp;
        for (int i = 0; i <= word1.size(); i++)
        {
            vector<int> temp(word2.size() + 1, 0);
            dp.push_back(temp);
        }
        for (int i = 0; i <= word1.size(); i++)
            dp[i][0] = i;
        for (int i = 0; i <= word2.size(); i++)
            dp[0][i] = i;
        for (int i = 1; i <= word1.size(); i++)
        {
            for (int k = 1; k <= word2.size(); k++)
            {  
                dp[i][k] = min(word1[i - 1] == word2[k - 1] ? dp[i - 1][k - 1] : dp[i - 1][k - 1] + 1, min(dp[i - 1][k] + 1, dp[i][k - 1] + 1));
            }
        }
        return dp.back().back();
    }
};

int main()
{
    Solution s;
    cout << s.minDistance("abc", "abcdef") << endl;
    cout << s.minDistance("bc", "abcdef") << endl;
    cout << s.minDistance("abcgdef", "abcdef") << endl;
    cout << s.minDistance("alsddkfjbc", "abcdef") << endl;
    cout << s.minDistance("abc", "abc") << endl;
    return 0;
}