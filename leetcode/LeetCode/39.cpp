#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
    {
        for (size_t i = 0; i < candidates.size(); i++)
            can.insert(candidates[i]);
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
            if (can.find(i) != can.end())
            {
                curStack.push_back(i);
                if (can.find(target - i) != can.end())
                {
                    vector<int> result(curStack);
                    result.push_back(target - i);
                    ret.push_back(result);
                }
                findTarget(target - i, i);
                curStack.pop_back();
            }
        }
    }

private:
    vector<int> curStack;
    set<int> can;
    vector<vector<int>> ret;
};

int main()
{
    Solution s;
    vector<int> candidate = { 1};
    vector<vector<int>> ret = s.combinationSum(candidate, 1);
    return 0;
}