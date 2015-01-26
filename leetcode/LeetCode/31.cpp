#include <iostream>
#include <vector>
#include <set>
using namespace std;
void nextPermutation(vector<int> &num) 
{
    if (num.size() <= 1)
        return;
    int len = num.size();
    int changeIndex = -1;
    for (int i = len - 2; i >= 0; i--)
    {
        if (num[i] < num.back())
        {
            changeIndex = i;
            break;
        }
        else
        {
            int temp = num[i];
            for (size_t k = i; k < len - 1; k++)
                num[k] = num[k + 1];
            num[len - 1] = temp;
        }
    }
    if (changeIndex != -1)
    {
        for (size_t i = changeIndex + 1; i < len; i++)
        {
            if (num[i] > num[changeIndex])
            {
                int temp = num[changeIndex];
                num[changeIndex] = num[i];
                num[i] = temp;
                break;
            }
        }
    }
}

int main()
{
    vector<int> num = { 1, 1, 5 };
    nextPermutation(num);
    return 0;
}