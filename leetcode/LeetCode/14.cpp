#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    string ret = "";
    if (strs.size() == 0)
        return ret;
    int shortLongth = strs[0].length();
    for (size_t i = 1; i < strs.size(); i++)
    {
        if (strs[i].length() < shortLongth)
            shortLongth = strs[i].length();
    }
    for (size_t i = 0; i < shortLongth; i++)
    {
        char curChar = strs[0][i];
        for (size_t k = 1; k < strs.size(); k++)
        {
            if (curChar != strs[k][i])
                return ret;
        }
        ret.push_back(curChar);
    }
    return ret;
}

int main()
{
    vector<string> strs = { "abcdgfhtrt" };
    cout << longestCommonPrefix(strs) << endl;
    return 0;
}