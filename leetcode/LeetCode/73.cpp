#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int> > &matrix) 
{
    vector<bool> row(matrix.size(), false);
    vector<bool> col(matrix[0].size(), false);
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t k = 0; k < matrix[i].size(); k++)
        {
            if (matrix[i][k] == 0)
            {
                row[i] = true;
                col[k] = true;
            }
        }
    }
    for (size_t i = 0; i < row.size(); i++)
    {
        if (row[i])
        {
            for (size_t k = 0; k < matrix[0].size(); k++)
            {
                matrix[i][k] = 0;
            }
        }
    }
    for (size_t i = 0; i < col.size(); i++)
    {
        if (col[i])
        {
            for (size_t k = 0; k < matrix.size(); k++)
            {
                matrix[k][i] = 0;
            }
        }
    }
}


int main()
{
    return 0;
}