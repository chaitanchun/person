#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S)
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
        for (size_t i = start; i < s.size(); i++)
        {
            current.push_back(s[i]);
            reverse(i + 1, s);
            current.pop_back();
        }
    }
    vector<vector<int>> ret;
    vector<int> current;
};

int main()
{
    Solution s;
    vector<int> a = { 1, 2, 3 };
    vector<vector<int>> ret = s.subsets(a);
    return 0;
}
