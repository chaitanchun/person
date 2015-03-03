#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S)
    {
        sort(S.begin(), S.end());
        reverse(0, S);
        return ret;
    }
private:
    void reverse(int start, vector<int> &s)
    {
        vector<int> temp = current;
        ret.push_back(temp);
        int pre;
        for (size_t i = start; i < s.size(); i++)
        {
            if (i == start || s[i] != pre)
            {
                current.push_back(s[i]);
                reverse(i + 1, s);
                pre = current.back();
                current.pop_back();
            }
        }
    }
    vector<vector<int>> ret;
    vector<int> current;
};

int main()
{
    Solution s;
    vector<int> a = { 1, 2, 2 };
    vector<vector<int>> ret = s.subsetsWithDup(a);
    return 0;
}