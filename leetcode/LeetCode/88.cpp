#include <iostream>
#include <algorithm>
using namespace std;

void merge(int A[], int m, int B[], int n) 
{
    for (int i = m - 1; i >= m; i--)
        A[i + n] = A[i];
    int i = 0;
    int k = 0;
    while (i < m && k < n)
    {
        if (A[i] < B[k])
        {
            A[i + k] = A[i + n];
            i++;
        }
        else
        {
            A[i + k] = B[k];
            k++;
        }
    }
}

int main()
{
    return 0;
}