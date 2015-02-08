#include <iostream>

#include <vector>
using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) 
    {
        int ret = 0;
        vector<vector<int>> dp;
        for (int i = 0; i < obstacleGrid.size(); i++)
        {
            vector<int> temp(obstacleGrid[i].size(), 0);
            dp.push_back(temp);
        }
        if (obstacleGrid[0][0])
            return ret;
        dp[0][0] = 1;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for (int i = 1; i <= n + m - 2; i++)
        {
            for (int k = 0; k <= i; k++)
            {
                if (k < m && i - k < n && obstacleGrid[k][i - k] == 0)
                {
                    if (k - 1 >= 0)
                        dp[k][i - k] += dp[k - 1][i - k];
                    if (i - k - 1 >= 0)
                        dp[k][i - k] += dp[k][i - k - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
    vector<vector<int>> ob;
    vector<int> a = { 0 };
    ob.push_back(a);
    vector<int> b = { 0 };
    ob.push_back(b);

    Solution s;
    int ret = s.uniquePathsWithObstacles(ob);
    return 0;
}