#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num)
    {
        for (size_t i = 0; i < num.size(); i++)
            selected.push_back(false);
        create(num);
        return ret;
    }
    void create(vector<int> &num)
    {
        if (result.size() == num.size())
        {
            ret.push_back(result);
            return;
        }
        set<int> currentSelection;
        for (size_t i = 0; i < num.size(); i++)
        {
            if (!selected[i] && currentSelection.find(num[i]) == currentSelection.end())
            {
                currentSelection.insert(num[i]);
                selected[i] = true;
                result.push_back(num[i]);
                create(num);
                result.pop_back();
                selected[i] = false;
            }
        }
    }
private:
    vector<vector<int>> ret;
    vector<bool> selected;
    vector<int> result;
};

int main()
{
    Solution s;
    vector<int> num = { 1, 1, 3 };
    vector<vector<int>> re = s.permuteUnique(num);
    return 0;
}