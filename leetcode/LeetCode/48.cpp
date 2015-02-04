#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int> > &matrix) 
{
    int n = matrix.size();
    for (size_t i = 0; i < n / 2; i++)
    {
        for (size_t k = i; k < n - 1 - i; k++)
        {
            int temp = matrix[i][k];
            matrix[i][k] = matrix[n - k - 1][i];
            matrix[n - k - 1][i] = matrix[n - i - 1][n - k - 1];
            matrix[n - i - 1][n - k - 1] = matrix[k][n - i - 1];
            matrix[k][n - i - 1] = temp;
        }
    }

}

int main()
{
    return 0;
}