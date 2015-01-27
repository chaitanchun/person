#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(int A[], int n, int target) 
{
    vector<int> ret;
    if (n == 0)
    {
        ret.push_back(-1);
        ret.push_back(-1);
        return ret;
    }
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (A[mid] > target)
        {
            end = mid - 1;
        }
        else if (A[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            if (mid == start || A[mid - 1] != target)
            {
                ret.push_back(mid);
                break;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    start = 0;
    end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (A[mid] > target)
        {
            end = mid - 1;
        }
        else if (A[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            if (mid == end || A[mid + 1] != target)
            {
                ret.push_back(mid);
                break;
            }
            else
            {
                start = mid + 1;
            }
        }
    }
    if (ret.size() != 2)
    {
        ret.push_back(-1);
        ret.push_back(-1);
    }
    return ret;
}

int main()
{
    int a[] = { 3, 4, 5, 6, 8 };
    vector<int> re = searchRange(a, 5, 8);
    return 0;
}