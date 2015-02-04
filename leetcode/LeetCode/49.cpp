#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
vector<string> anagrams(vector<string> &strs) 
{
    vector<string> ret;
    map<string, pair<int, int>> hash;

    for (size_t i = 0; i < strs.size(); i++)
    {
        string str = strs[i];
        sort(str.begin(), str.end());
        size_t index = str.find_first_not_of(' ');
        if (index != string::npos)
            str = str.substr(index);
        auto it = hash.find(str);
        if (it != hash.end())
        {
            if (it->second.first == 1)
                ret.push_back(strs[it->second.second]);
            it->second.first = it->second.first + 1;
            ret.push_back(strs[i]);
        }
        else
        {
            hash.insert(make_pair(str, make_pair(1, i)));
        }
    }
    return ret;
}

int main()
{
    vector<string> strs = { "", "" };
    vector<string> ret = anagrams(strs);
    return 0;
}