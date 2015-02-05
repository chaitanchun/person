#include <iostream>
#include <vector>

using namespace std;
vector<vector<int> > generateMatrix(int n) 
{
    vector<vector<int>> ret;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(n);
        ret.push_back(temp);
    }
    int num = (n + 1) / 2;
    int cur = 1;
    for (int i = 0; i < num; i++)
    {
        int k;
        for (k = i; k < n - i; k++)
            ret[i][k] = cur++;
        for (k = i + 1; k < n - i; k++)
            ret[k][n - 1 - i] = cur++;
        for (k = n - 2 - i; k >= i && n - 1 != 2 * i; k--)
            ret[n - 1 - i][k] = cur++;
        for (k = n - 2 - i; k >= i + 1 && n - 1 != 2 * i; k--)
            ret[k][i] = cur++;
    }
    return ret;
}

int main()
{
    vector<vector<int>> ret = generateMatrix(3);
    return 0;
}