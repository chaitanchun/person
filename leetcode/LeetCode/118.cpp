#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > generate(int numRows) 
{
    vector<vector<int>> ret;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> row;
        for (int k = 0; k <= i; k++)
        {
            if (k == 0 || k == i)
                row.push_back(1);
            else
                row.push_back(ret[i - 1][k - 1] + ret[i - 1][k]);
        }
        ret.push_back(row);
    }
    return ret;
}

int main()
{
    return 0;
}