#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <set>
using namespace std;
vector<int> findSubstring(string S, vector<string> &L) {
   /* vector<int> ret;
    unordered_map<string, unordered_set<int>> hash;
    vector<int> order;
    vector<int> index;
    int len = L[0].length();
    for (size_t i = 0; i < L.size(); i++)
    {
        unordered_set<int> set;
        hash.insert(make_pair(L[i], set));
    }
    for (size_t i = 0; i < S.length() - len + 1; i++)
    {
        string substr = S.substr(i, len);
        for (size_t k = 0; k < L.size(); k++)
        {
            if (substr == L[k])
            {
                hash[L[k]].insert(i);
                order.push_back(i);
                index.push_back(k);
                break;
            }
        }
    }
    for (size_t i = 0; i < order.size(); i++)
    {
        unordered_set<string> used;
        used.insert(L[index[i]]);
        for (size_t k = 1; k < L.size() && used.size() == k; k++)
        {
            for (size_t n = 0; n < L.size(); n++)
            {
                if (used.find(L[n]) == used.end())
                {
                    if (hash[L[n]].find(order[i] + k * len) != hash[L[n]].end())
                    {
                        used.insert(L[n]);
                        break;
                    }
                }
            }
        }
        if (used.size() == L.size())
            ret.push_back(order[i]);
    }
    return ret;*/
}


int main()
{
    vector<string> L = { "foo", "bar" };
    vector<int> ret = findSubstring("barfoothefoobarman", L);
    return 0;
}