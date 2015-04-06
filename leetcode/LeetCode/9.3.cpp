#include <iostream>
#include <vector>

using namespace std;

bool findMagicIndex(const vector<int> &arr, int start, int end)
{
    if (start > end)
        return false;
    int mid = (start + end) / 2;
    if (mid > arr[mid])
        return findMagicIndex(arr, mid + 1, end);
    else if (mid < arr[mid])
        return findMagicIndex(arr, start, mid - 1);
    else
        return true;
}

int main()
{
    return 0;
}