#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(int A[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        if (A[i] <= n && A[i] > 0 && A[i] - 1 != i)
        {
            int cur = A[i]; 
            A[i] = 0;
            while (cur <= n && cur > 0 && cur != A[cur - 1])
            {
                int temp = A[cur - 1];
                A[cur - 1] = cur;
                cur = temp;
            }
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        if (i + 1 != A[i])
            return i + 1;
    }
    return n + 1;
}

int main()
{
    int A[] = { 1, 2, 0 };

    cout << firstMissingPositive(A, 3) << endl;
    int B[] = { 3, 4, -1, 1 };
    cout << firstMissingPositive(B, 4) << endl;    
    return 0;
}