#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k)
    {
        if (n == 0 || k == 0)
            return;
        vector<int> ret;
        k = n - k % n;
        if (k == n)
            k = 0;
        for (int i = 0; i < n; i++)
        {
            ret.push_back(nums[k++]);
            if (k == n)
                k = 0;
        }
        for (int i = 0; i < n; i++)
            nums[i] = ret[i];
    }
};

int main()
{
    Solution s;
    int nums[1] = { -1 };
    s.rotate(nums, 1, 1);

    return 0;
}