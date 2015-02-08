#include <iostream>
#include <vector>
using namespace std;
vector<int> plusOne(vector<int> &digits) {
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (digits[i] != 9)
        {
            digits[i]++;
            return digits;
        }
        else
            digits[i] = 0;
    }
    vector<int> ret(digits.size() + 1);
    ret[0] = 1;
    copy(digits.begin(), digits.end(), ret.begin() + 1);
    return ret;
}

int main()
{
    return 0;
}