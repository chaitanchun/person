#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
vector<int> grayCode(int n) 
{
    vector<bool> has(pow(2, n), false);
    vector<int> ret;
    ret.push_back(0);
    int cur = 0;
    int num = pow(2, n) - 1;
    has[0] = true;
    while (num)
    {
        int base = 1;
        for (size_t i = 0; i < n; i++)
        {
            int temp;
            if ((cur & base) == 0)
                temp = cur | base;
            else
                temp = cur & ~base;
                
            if (!has[temp])
            {
                has[temp] = true;
                cur = temp;
                num--;
                ret.push_back(cur);
                break;
            }
            base = base << 1;
        }
    }
    return ret;
}

int main()
{
    vector<int> ret = grayCode(3);
    return 0;
}