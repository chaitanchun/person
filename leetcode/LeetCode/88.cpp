#include <iostream>
#include <algorithm>
using namespace std;

void merge(int A[], int m, int B[], int n) 
{
    for (int i = m - 1; i >= 0; i--)
        A[i + n] = A[i];
    int i = 0;
    int k = 0;
    while (i < m && k < n)
    {
        if (A[i + n] < B[k])
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
    while (i < m)
    {
        A[i + k] = A[i + n];
        i++;
    }
    while (k < n)
    {
        A[i + k] = B[k];
        k++;
    }
}

int main()
{
    int a[9] = {1, 3, 4, 5, 9};
    int b[4] = { 1, 2, 5, 6 };
    merge(a, 5, b, 4);
    return 0;
}