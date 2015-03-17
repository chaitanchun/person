#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) 
    {
        int min = num[0];
        for (size_t i = 1; i < num.size(); i++)
            if (num[i] < min)
                min = num[i];
        return min;
    }
};

int main()
{
    return 0;
}