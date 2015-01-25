#include <iostream>

using namespace std;

int removeElement(int A[], int n, int elem) {
    int num = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (A[i] == elem)
            num++;
        else
            A[i - num] = A[i];
    }
    return n - num;
}


int main()
{
    return 0;
}