#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) 
    {
        int ret = 0;
        for (int i = 0; i < n; i++)
            ret ^= A[i];
        return ret;
    }
};

int main()
{
    return 0;
}