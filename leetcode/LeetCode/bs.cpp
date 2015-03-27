#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr;
    arr.reserve(20);
    for (size_t i = 0; i < 20; i++)
        arr.push_back(i);

    int target = 21;
    int start = 0;
    int end = arr.size() - 1;
    bool find = false;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if(arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            find = true;
            break;
        }
    }

    return 0;
}