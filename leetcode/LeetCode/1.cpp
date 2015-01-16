#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> ret;
    vector<int> orginal = numbers;
    sort(numbers.begin(), numbers.end());
    int begin = 0;
    int end = numbers.size() - 1;
    int first = 0;
    int second = 0;
    while (begin < end)
    {
        int twoSum = numbers[begin] + numbers[end];
        if (twoSum > target)
        {
            end--;
        }
        else if (twoSum < target)
        {
            begin++;
        }
        else
        {
            for (int i = 0; i < orginal.size(); i++)
            {
                if (orginal[i] == numbers[begin] && first == 0)
                {
                    first = i + 1;
                    if (second != 0)
                        break;
                }
                else if (orginal[i] == numbers[end] && second == 0)
                {
                    second = i + 1;
                    if (first != 0)
                        break;
                }
            }
            if (first < second)
            {
                ret.push_back(first);
                ret.push_back(second);
            }
            else
            {
                ret.push_back(second);
                ret.push_back(first);
            }
            break;
        }
    }
    return ret;
}


int main()
{
    vector<int> number = { 0, 4, 3, 0 };
    int target = 0;
    vector<int> ret = twoSum(number, target);

    return 0;
}