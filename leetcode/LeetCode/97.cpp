#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) 
    {  
        if (s1.length() + s2.length() != s3.length())
            return false;

        vector<vector<bool>> f(s1.length() + 1, vector<bool>(s2.length() + 1, true));
        for (size_t i = 1; i <= s1.length(); i++)
            f[i][0] = f[i - 1][0] && s1[i - 1] == s3[i - 1];
        for (size_t i = 1; i <= s2.length(); i++)
        {
            f[0][i] = f[0][i - 1] && s2[i - 1] == s3[i - 1];

        }

        for (size_t i = 1; i <= s1.length(); i++)
            for (size_t j = 1; j <= s2.length(); j++)
                f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j])
                || (s2[j - 1] == s3[i + j - 1] && f[i][j - 1]);
        return f[s1.length()][s2.length()];


    }
};

int main()
{
    return 0;
}