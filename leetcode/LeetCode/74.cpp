#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int> > &matrix, int target)
{
    if (matrix.size() == 0 || matrix[0].size() == 0)
        return false;
    int m = matrix.size();
    int n = matrix[0].size();
    int row = -1;
    int start = 0;
    int end = m - 1;
    while (start <= end) 
    {
        int mid = (start + end) / 2;
        if (matrix[mid][0] > target)
        {
            end = mid - 1;
        }
        else if (matrix[mid][0] < target)
        {
            if (end - 1 == start)
            {
                row = matrix[end][0] <= target ? end : start;
                break;
            }
            else if (end == start)
            {
                row = start;
                break;
            }
            start = mid;
        }
        else
        {
            return true;
        }
    }
    if (row == -1 || matrix[row].back() < target)
        return false;

    //binary search
    start = 0;
    end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (matrix[row][mid] > target)
            end = mid - 1;
        else if (matrix[row][mid] < target)
            start = mid + 1;
        else
            return true;
    }
    return false;
}


int main()
{
    vector<int> a = { 1, 3, 5, 7 };
    vector<int> b = { 10, 11, 16, 20 };
    vector<int> c = { 23, 30, 34, 50 };
    vector<int> d = { 123, 130, 134, 150 };
    vector<int> ad = {1};
    vector<int> bd = {3};

    vector<vector<int>> m = { ad, bd };
    cout<< searchMatrix(m, 3)<<endl;
    cout<< searchMatrix(m, 0)<<endl;
    cout<< searchMatrix(m, 9)<<endl;
    cout<< searchMatrix(m, 11)<<endl;
    cout<<searchMatrix(m, 35)<<endl;
    cout<< searchMatrix(m, 34)<<endl;
    cout<< searchMatrix(m, 60)<<endl;
    return 0;
}