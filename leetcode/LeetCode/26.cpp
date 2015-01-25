#include <iostream>

using namespace std;
int removeDuplicates(int A[], int n) {
    int dup = 0;
    for (size_t i = 1; i < n; i++)
    {
        if (A[i] == A[i - dup - 1])
            dup++;
        else if (dup > 0)
            A[i - dup] = A[i];
    }
    return n - dup;
}

int main()
{
    int a[3] = { 1, 1, 2 };
    int n = removeDuplicates(a, 3);

    return 0;
}