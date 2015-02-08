#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int num = m - 1 + n - 1;
        int b = min(m, n) - 1;
        long long div = 1;
        for (int i = 0; i < b; i++)
            div = div * (num - i) / (i + 1);
        return (int)div;
    }
};
int main()
{
    Solution s;
    int ret = s.uniquePaths(3, 7);
    return 0;
}