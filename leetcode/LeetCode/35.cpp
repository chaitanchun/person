#include <iostream>

using namespace std;

int searchInsert(int A[], int n, int target) {
    if (n == 0)
        return 0;
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (A[mid] > target)
            end = mid - 1;
        else if (A[mid] < target)
            start = mid + 1;
        else
            return mid;
    }
    return start;
}

int main()
{
    int a[] = { 1, 3, 5, 6 };
    cout << searchInsert(a, 4, 0) << endl;
    return 0;
}