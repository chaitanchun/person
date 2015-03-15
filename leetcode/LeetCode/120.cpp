#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) 
    {
        if (triangle.size() == 0)
            return 0;
        vector<int> dp(triangle.size());
        dp[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++)
        {
            int prev = 0;
            for (int k = 0; k < triangle[i].size(); k++)
            {
                int min = triangle[i][k];
                if (k != 0 && k != triangle[i].size() - 1)
                    min += (prev < dp[k] ? prev : dp[k]);
                else if (k == 0)
                    min += dp[k];
                else
                    min += prev;
                prev = dp[k];
                dp[k] = min;
            }
        }
        int ret = dp[0];
        for (int i = 1; i < dp.size(); i++)
            if (dp[i] < ret)
                ret = dp[i];
        return ret;
    }
};

int main()
{
    return 0;
}