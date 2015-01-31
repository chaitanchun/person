#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        for (size_t i = 0; i < num.size(); i++)
        {
            if (can.find(num[i]) != can.end())
                can[num[i]] = can[num[i]] + 1;
            else
                can.insert(make_pair(num[i], 1));
        }
        if (can.find(target) != can.end())
        {
            vector<int> result;
            result.push_back(target);
            ret.push_back(result);
        }
        findTarget(target, 1);
        return ret;
    }
    void findTarget(int target, int min)
    {
        for (size_t i = min; i <= target / 2; i++)
        {
            auto it = can.find(i);
            if (it != can.end() && it->second > 0)
            {
                curStack.push_back(i);
                it->second = it->second - 1;
                if (can.find(target - i) != can.end() && can[target - i] > 0)
                {
                    vector<int> result(curStack);
                    result.push_back(target - i);
                    ret.push_back(result);
                }
                findTarget(target - i, i);
                it->second = it->second + 1;
                curStack.pop_back();
            }
        }
    }
private:
    vector<int> curStack;
    map<int, int> can;
    vector<vector<int>> ret;
};

int main()
{
    Solution s;
    vector<int> can = { 1, 1};
    vector<vector<int>> ret = s.combinationSum2(can, 2);
    return 0;
}