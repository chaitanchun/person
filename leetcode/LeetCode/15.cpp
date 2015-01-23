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

    for (auto i = newMap.begin(); i != newMap.end() && i->first < 0; i++)
    {
        int target = 0 - i->first;
        int startIndex = 0;
        for (size_t k = 0; k < newNum.size() - 2; k++)
        {
            if (newNum[k] == i->first)
            {
                startIndex = k + 1;
                break;
            }
        }
        if (startIndex == 0)
            break;
        int incIndex = startIndex + 1;
        int decIndex = startIndex;
        float half = float(target) / 2.0f;

        if (newNum[startIndex] + newNum[startIndex + 1] > target || newNum[newNum.size() - 2] + newNum.back() < target)
        {
            continue;
        }
        else
        {
            for (size_t k = newNum.size() - 1; k > startIndex + 1; k--)
            {
                if (target % 2 == 0 && newNum[k] == target / 2)
                {
                    if (newNum[k - 1] == target / 2)
                    {
                        incIndex = k;
                        decIndex = k - 1;
                    }
                    else
                    {
                        incIndex = k + 1;
                        decIndex = k - 1;
                    }
                    break;
                }
                else if (float(newNum[k]) > half && float(newNum[k - 1]) < half)
                {
                    incIndex = k;
                    decIndex = k - 1;
                    break;
                }
            }
        }

        // 2 sum 
        while (incIndex < newNum.size() && decIndex >= startIndex)
        {
            int sum = newNum[incIndex] + newNum[decIndex];
            if (sum == target)
            {
                vector<int> value = { i->first, newNum[decIndex], newNum[incIndex] };
                ret.push_back(value);
                do
                {
                    incIndex++;
                } while (incIndex < newNum.size() && newNum[incIndex] == newNum[incIndex - 1]);
                do
                {
                    decIndex--;
                } while (decIndex >= startIndex && newNum[decIndex] == newNum[decIndex + 1]);
            }
            else if (sum > target)
            {
                do
                {
                    decIndex--;
                } while (decIndex >= startIndex && newNum[decIndex] == newNum[decIndex + 1]);
            }
            else
            {
                do
                {
                    incIndex++;
                } while (incIndex < newNum.size() && newNum[incIndex] == newNum[incIndex - 1]);
            }
        }
    }
    return ret;
}
int main()
{
    vector<int> n = { 2, -3, 0, -2, -5, -5, -4, 1, 2, -2, 2, 0, 2, -4 };
    vector<vector<int>> a = threeSum(n);
    vector<int> nums = { 7, -1, 14, -12, -8, 7, 2, -15, 8, 8, -8, -14, -4, -5, 7, 9, 11, -4, -15, -6, 1, -14, 4, 3, 10, -5, 2, 1, 6, 11, 2, -2, -5, -7, -6, 2, -15, 11, -6, 8, -4, 2, 1, -1, 4, -6, -15, 1, 5, -15, 10, 14, 9, -8, -6, 4, -6, 11, 12, -15, 7, -1, -9, 9, -1, 0, -4, -1, -12, -2, 14, -9, 7, 0, -3, -4, 1, -2, 12, 14, -10, 0, 5, 14, -1, 14, 3, 8, 10, -8, 8, -5, -2, 6, -11, 12, 13, -7, -12, 8, 6, -13, 14, -2, -5, -11, 1, 3, -6 };
    vector<vector<int>> ret = threeSum(nums);
    return 0;

}