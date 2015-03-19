#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n)
    {
        if (n == 1)
            return A[0];
        int ret = INT_MIN;
        int maxPo = 1;
        int maxNe = -1;
        int first = true;
        int po = false;
        for (int i = 0; i < n; i++)
        {
            if (A[i] < 0)
            {
                int temp = maxNe;
                maxNe = maxPo * A[i];
                if (first)
                {
                    if (po & maxPo > ret)
                        ret = maxPo;
                    maxPo = 1;
                    first = false;
                }
                else
                {
                    if (po && maxPo > ret)
                        ret = maxPo;
                    maxPo = temp * A[i];
                    po = true;
                }
            }
            else if (A[i] > 0)
            {
                if (!first)
                    maxNe *= A[i];
                maxPo *= A[i];
                po = true;
            }
            else
            {
                if (po && maxPo > ret)
                    ret = maxPo;
                else if (0 > ret)
                    ret = 0;
                maxPo = 1;
                first = true;
                maxNe = -1;
                po = false;
            }
        }
        if (po && maxPo > ret)
            ret = maxPo;
        return ret;
    }
};

int main()
{
    Solution s;
    int a[] = { 6, 3, -10, 0, 2 };
    int ret = s.maxProduct(a, 5);
    return 0;
}