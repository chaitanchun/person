#include <iostream>

using namespace std;

bool canJump(int A[], int n) 
{
    int max = 1;
    for (int i = 0; i < n - 1; i++)
    {
        max--;
        if (A[i] == 0 && max == 0)
        {
            return false;
        }
        else
        {
            if (A[i] > max)
                max = A[i];
        }
    }
    return max > 0 ? true : false;
}

int main()
{
    int a[] = { 0 };
    cout << canJump(a, 1) << endl;
    return 0;
}