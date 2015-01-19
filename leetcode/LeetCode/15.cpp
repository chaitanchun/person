#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
vector<vector<int> > threeSum(vector<int> &num)
{
    vector<vector<int>> ret;
    if (num.size() < 3)
        return ret;

    map<int, int> newMap;
    for (size_t i = 0; i < num.size(); i++)
    {
        auto it = newMap.find(num[i]);
        if (it != newMap.end())
        {
            if (it->second == 1)
                it->second = 2;
            else if (it->first == 0 && it->second == 2)
            {
                it->second = 3;
                vector<int> value = { 0, 0, 0 };
                ret.push_back(value);
            }
        }
        else
        {
            newMap.insert(make_pair(num[i], 1));
        }
    }
    auto zero = newMap.find(0);
    if (zero != newMap.end())
        zero->second = 1;
    vector<int> newNum;
    for (auto i = newMap.begin(); i != newMap.end(); i++)
    {
        for (int k = 0; k < i->second; k++)
            newNum.push_back(i->first);
    }

    for (auto i = newMap.begin(); i != newMap.end(); i++)
    {
        int target = 0 - i->first;
        int incIndex = 0;
        int decIndex = 0;

        auto it = newMap.find(target);

        for (size_t k = newNum.size() - 1; k > 0 ; k++)
        {
            if (it != newMap.end() && it->second == 2)
            {
                if (newNum[k] == target)
                {
                    incIndex = k;
                    decIndex = k - 1;
                }
            }
            else if (newNum[k] >= target && newNum[k - 1] < target)
            {
                incIndex = k;
                decIndex = k - 1;
            }
        }
        // 2 sum 
        if (incIndex == 0)
            continue;
        while (incIndex < newNum.size() && decIndex > 0)
        {
            int sum = newNum[incIndex] + newNum[decIndex];
            if (sum == target)

        }

    }

    for (size_t i = 0; i < newNum.size(); i++)
    {
        int target = 0 

    }
    int first = 0;
    int second = 1;
    int third = 2;
    for (size_t i = 2; i < newNum.size(); i++)
    {
        if (newNum[i] >= 0)
        {
            third = i;
            break;
        }
    }
    if (newNum[third] < 0)
        return ret;
    for (size_t i = 0; i < third; i++)
    {
        for (size_t k = third; k < newNum.size(); k++)
        {
            for (size_t j = i + 1; j < k; j++)
            {
                int threeSum = newNum[i] + newNum[j] + newNum[k];
                if (threeSum > 0)
                {
                    break;
                }
                else if (threeSum < 0)
                {
                    continue;
                }
                else
                {
                    vector<int> trip = { newNum[i], newNum[j], newNum[k] };
                    bool isSame = false;
                    for (size_t n = 0; n < ret.size(); n++)
                    {
                        if (ret[n][0] == trip[0] && ret[n][1] == trip[1] && ret[n][2] == trip[2])
                            isSame = true;
                    }
                    if (!isSame)
                        ret.push_back(trip);
                }
            }
        }
    }
    return ret;
}
int main()
{
    vector<int> nums = { 7, -1, 14, -12, -8, 7, 2, -15, 8, 8, -8, -14, -4, -5, 7, 9, 11, -4, -15, -6, 1, -14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7, -6, 2, -15, 11, -6, 8, -4, 2, 1, -1, 4, -6, -15, 1, 5, -15, 10, 14, 9, -8, -6, 4, -6, 11, 12, -15, 7, -1, -9, 9, -1, 0, -4, -1, -12, -2, 14, -9, 7, 0, -3, -4, 1, -2, 12, 14, -10, 0, 5, 14, -1, 14, 3, 8, 10, -8, 8, -5, -2, 6, -11, 12, 13, -7, -12, 8, 6, -13, 14, -2, -5, -11, 1, 3, -6 };
    vector<vector<int>> ret = threeSum(nums);
    return 0;

}