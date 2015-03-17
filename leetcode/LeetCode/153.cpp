#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> &num)
{
    int n = num.size();
    int start = 0;
    int end = n - 1;
    int pivot = 0;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (num[mid] > num[end])
        {
            if (num[mid] > num[mid + 1])
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
            if (mid == start || num[mid - 1] > num[mid])
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
    return num[pivot];
}

int main()
{
    return 0;

}