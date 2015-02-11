#include <iostream>
using namespace std;

int removeDuplicates(int A[], int n) 
{
    if (n <= 2)
        return n;
    int num = 2;
    for (int i = 2; i < n; i++)
    {
        if (A[i] != A[num - 2])
            A[num++] = A[i];
    }
    return num;
}

int main()
{
    int a[] = { 1, 1, 1, 2, 2, 3 };
    int ret = removeDuplicates(a, 6);
    return 0;
}