#include <iostream>

#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int min = prices[0];
        int max = prices[0];
        int ret = 0;
        for (size_t i = 1; i < prices.size(); i++)
        {
            if (prices[i] >= prices[i - 1])
            {
                max = prices[i];
            }
            else
            {
                ret += max - min;
                min = prices[i];
                max = prices[i];
            }
        }
        ret += max - min;
        return ret;
    }
};

int main()
{
    return 0;
