#include <iostream>

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > combine(int n, int k) 
    {
        num = n;
        reverse(0, k);
        return ret;
    }
private:
    void reverse(int start, int k)
    {
        if (k == 0)
        {
            vector<int> temp = current;
            ret.push_back(temp);
            return;
        }

        for (size_t i = start; i < num; i++)
        {
            current.push_back(i + 1);
            reverse(i + 1, k - 1);
            current.pop_back();
        }
    }
    vector<vector<int>> ret;
    vector<int> current;
    int num;
};

int main()
{
    Solution s;
    vector<vector<int>> ret = s.combine(4, 2);
    return 0;
}