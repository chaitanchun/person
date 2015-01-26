#include <iostream>

using namespace std;

int search(int A[], int n, int target) 
{
    int index = -1;
    if (n == 0)
        return index;
    int start = 0;
    int end = n - 1;
    int pivot = 0;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (A[mid] > A[end])
        {
            if (A[mid] > A[mid + 1])
            {
                pivot = mid + 1;
                break;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if (mid == start || A[mid - 1] > A[mid])
            {
                pivot = mid;
                break;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    // search 
    start = 0;
    end = n - 1;
    while (start <= end)
    {
        int mid = ((start + end) / 2 + pivot) % n;
        if (A[mid] > target)
            end = (start + end) / 2 - 1;
        else if (A[mid] < target)
            start = (start + end) / 2 + 1;
        else
        {
            index = mid;
            break;
        }
    }
    return index;
}

int main()
{
    int A[] = { 7, 0, 1, 2, 4, 5, 6 };
    int re = search(A, 7, 5);
    return 0;

}