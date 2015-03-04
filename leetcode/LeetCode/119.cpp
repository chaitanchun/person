#include <iostream>
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex)
{
    vector<int> ret;
    for (int i = 0; i <= rowIndex; i++)
    {
        int pre = 1;
        for (int k = 1; k < i; k++)
        {
            int temp = pre + ret[k];
            pre = ret[k];
            ret[k] = temp;
        }
        ret.push_back(1);
    }
    return ret;
}

int main()
{
    return 0;
}