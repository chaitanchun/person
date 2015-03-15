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
        int ret = 0;
        for (size_t i = 1; i < prices.size(); i++)
        {
            if (prices[i] - min > ret)
                ret = prices[i] - min;
            if (prices[i] < min)
                min = prices[i];
        }
        return ret;
    }
};

int main()
{
    return 0;
}