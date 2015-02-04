#include <iostream>
#include <vector>
using namespace std; 

int maxSubArray(int A[], int n) {
    int ret = A[0];
    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum >= 0)
        {
            if (sum > ret)
                ret = sum;
        }
        else
        {
            if (A[i] > ret)
                ret = A[i];
            sum = 0;
        }
    }
    return ret;
}

int main()
{
    int A[] = {-2, -1};
    cout << maxSubArray(A, 2);
    return 0;
}