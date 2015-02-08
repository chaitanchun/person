#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid)
    {
        vector<vector<int>> dp;
        for (int i = 0; i < grid.size(); i++)
        {
            vector<int> temp(grid[i].size(), INT_MAX);
            dp.push_back(temp);
        }
        dp[0][0] = grid[0][0];
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 1; i <= n + m - 2; i++)
        {
            for (int k = 0; k <= i; k++)
            {
                if (k < m && i - k < n)
                {
                    if (k - 1 >= 0)
                        dp[k][i - k] = min(dp[k - 1][i - k] + grid[k][i - k], dp[k][i - k]);
                    if (i - k - 1 >= 0)
                        dp[k][i - k] = min(dp[k][i - k - 1] + grid[k][i - k], dp[k][i - k]);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main()
{
       return 0;
}