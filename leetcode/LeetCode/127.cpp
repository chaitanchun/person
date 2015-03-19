#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) 
    {
        if (start == end)
            return 0;
        queue<string> que;
        unordered_map<string, bool> visited;
        unordered_map<string, vector<string>> match;
        dict.insert(start);
        dict.insert(end);
        for (auto it = dict.begin(); it != dict.end(); it++)
        {
            for (int i = 0; i < (*it).size(); i++)
            {
                string curr = *it;
                curr[i] = '.';
                auto ito = match.find(curr);
                if (ito != match.end())
                {
                    ito->second.push_back(*it);
                }
                else
                {
                    vector<string> temp;
                    temp.push_back(*it);
                    match.insert(make_pair(curr, temp));
                }
            }
            visited.insert(make_pair(*it, false));
        }
        que.push(start);
        int ret = 1;
        int num = 1;
        int nextnum = 0;
        while (que.size() > 0)
        {
            visited[que.front()] = true;
            for (size_t i = 0; i < que.front().size(); i++)
            {
                string cur = que.front();
                cur[i] = '.';
                auto it = match.find(cur);
                if (it != match.end())
                {
                    for (size_t k = 0; k < it->second.size(); k++)
                    {
                        if (it->second[k] == end)
                        {
                            return ret + 1;
                        }
                        else if (!visited[it->second[k]])
                        {
                            que.push(it->second[k]);
                            nextnum++;
                        }
                    }
                }
            }
            que.pop();
            if (--num == 0)
            {
                num = nextnum;
                nextnum = 0;
                ret++;
            }
        }
        return 0;
    }
};

int main()
{
    Solution s;
    unordered_set<string> dic;
    dic.insert("hot");
    dic.insert("dot");
    dic.insert("dog");
    dic.insert("lot");
    dic.insert("log");
    int ret = s.ladderLength("hit", "cog", dic);

    return 0;
}