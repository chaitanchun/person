#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) 
    {
        stack<int> sta;
        int max_area = 0;
        for (int i = 0; i <= height.size(); i++)
        {

            int height_bound = (i == height.size()) ? 0 : height[i];
            while (sta.size() != 0)
            {
                int h = height[sta.top()];
                if (h < height_bound)
                    break;
                sta.pop();
                int index_bound = sta.size() == 0 ? -1 : sta.top();
                max_area = max(max_area, h * (i - 1 - index_bound));
            }
            sta.push(i);
        }
        return max_area;
    }
};

int main()
{
    return 0;
}