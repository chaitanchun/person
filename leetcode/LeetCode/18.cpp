#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int>> ret;
    unordered_map<int, vector < int >> cache;
    sort(num.begin(), num.end());
    for (size_t i = 0; i < num.size() - 4; i++)
    {
        for (size_t k = 1; k < num.size() - 3; k++)
        {
            int newTarget = target - num[i] - num[k];
            auto it = cache.find(newTarget);
            if (it != cache.end())
            {

            }
            else
            {

            }

        }

    }




    return ret;
}

int main()
{
    return 0;
}