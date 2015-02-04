#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> spiralOrder(vector<vector<int> > &matrix) 
{
    vector<int> ret;
    if (matrix.size() == 0)
        return ret;
    int num = (min(matrix.size(), matrix[0].size()) + 1) / 2;
    int m = matrix.size();
    int n = matrix[0].size();
    
    for (int i = 0; i < num; i++)
    {
        int k;
        for ( k = i; k < n - i; k++)
        {
            ret.push_back(matrix[i][k]);
        }
        for ( k = i + 1; k < m - i; k++)
        {
            ret.push_back(matrix[k][n - 1 - i]);
        }
        for ( k = n - 2 - i; k >= i && m - 1 != 2 * i; k--)
        {
            ret.push_back(matrix[m - 1 - i][k]);
        }
        for ( k = m - 2 - i; k >= i + 1 && n - 1 != 2 * i; k--)
        {
            ret.push_back(matrix[k][i]);
        }
    }
    return ret;
}

int main()
{
    vector<int> a = { 1, 2, 3, 4};
    vector<int> b = { 10, 11, 12, 5};
    vector<int> c = { 9, 8, 7, 6};
    vector<vector<int>> matrix = { a, b, c };
    vector<int> ret = spiralOrder(matrix);
    return 0;
}