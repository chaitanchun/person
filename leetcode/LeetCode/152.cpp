#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) 
    {
        int ret = A[0];
        if (n == 1)
            return A[0];
        int maxPo = 1;
        int maxNe = -1;
        for (int i = 0; i < n; i++)
        {
            if (A[i] < 0)
            {
                int temp = maxPo;
                maxPo = maxNe * A[i];
                if (maxPo > ret)
                    ret = maxPo;
                maxNe = temp * A[i];
            }
            else if (A[i] > 0)
            {

            }
            else
            {

            }
        }
        return ret;
    }
};

int main()
{
    return 0;
}