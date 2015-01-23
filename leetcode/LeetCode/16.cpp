#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;
int threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    int ret = num[0] + num[1] + num[2];
    for (size_t i = 0; i < num.size() - 2; i++)
    {
        int newTarget = target - num[i];
        int start = i + 1;
        int end = num.size() - 1;
        int nearest = num[start] + num[end] - newTarget;
        while (start < end)
        {
            int value = num[start] + num[end] - newTarget;
            if (value > 0)
                end--;
            else if (value < 0)
                start++;
            else
                return target;
            if (abs(value) < abs(nearest))
                nearest = value;
        }
        if (abs(nearest) < abs(ret - target))
            ret = nearest + target;
    }
    return ret;
}


int main()
{
    vector<int> num = { 1, 1, -1 };
    cout << threeSumClosest(num, 2) << endl;
    return 0;
}