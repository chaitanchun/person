#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    //at most 2 tranctions
    //Dynamic Programming
    //zero0: profit after 1 transaction, no stock left
    //zero1: profit after 2 transactions,no stock left
    //one0:  profit after 0 transaction, 1  stock left
    //one1:  profit after 1 transaction, 1  stock left
    int maxProfit3(vector<int> prices){
        if (prices.size()<2)return 0;
        int zero0 = 0, zero1 = 0, one0 = -prices[0], one1 = INT_MIN;
        for (int i = 1; i<prices.size(); i++){
            if (zero0 != 0){
                zero1 = max(zero1, one1 + prices[i]);
                one1 = max(one1, zero0 - prices[i]);
            }
            zero0 = max(zero0, one0 + prices[i]);
            one0 = max(one0, -prices[i]);
        }
        return max(zero0, zero1);
    }
};

int main()
{
    return 0;
}