#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        stack<char> sta;
        generate(n, "", sta);
        return ret;
    }

    void generate(int num, string pare, stack<char> &sta)
    {
        if (num > 0)
        {
            sta.push('(');
            generate(num - 1, pare + "(", sta);
            sta.pop();
            if (sta.size() > 0)
            {
                sta.pop();
                generate(num, pare + ")", sta);
                sta.push('(');
            }
        }
        else
        {
            for (size_t i = 0; i < sta.size(); i++)
                pare += ")";
            ret.push_back(pare);
        }
    }
private:
    vector<string> ret;
};

int main()
{
    Solution s;
    vector<string> ret = s.generateParenthesis(3);
    return 0;
}