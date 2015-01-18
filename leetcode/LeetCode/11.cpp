#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm> 
using namespace std;

int maxArea(vector<int> &height) {
    int result = 0;
    int l = 0;
    int r = height.size() - 1;
    while (l < r) {
        int area = (r - l) * min(height[l], height[r]);
        result = max(result, area);
        if (height[l] < height[r]) {
            do {
                l++;
            } while (l < r && height[l - 1] >= height[l]);
        }
        else {
            do {
                r--;
            } while (r > l && height[r + 1] >= height[r]);
        }
    }
    return result;
}

int main()
{
    return 0;
}