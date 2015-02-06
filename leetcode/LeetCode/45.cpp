#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int jump(vector<int> A, int n) 
    {
        int i = 0, j = 1, cnt = 0, mx;

        if (n == 1) return 0;

        while (i < n - 1 && i + A[i] < n - 1) {
            for (mx = j; j <= i + A[i]; j++) { mx = (mx + A[mx] <= j + A[j]) ? j : mx; }
            i = mx; cnt++;
        }
        return ++cnt;
    }
};

int main()
{
    Solution s;
    vector<int> a = {1, 2, 0, 1};
    cout << s.jump(a, a.size()) << endl;
    return 0;
}