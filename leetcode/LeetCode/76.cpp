#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
using namespace std;

string minWindow(string S, string T)
{
    string ret;
    unordered_map<char, int> count;
    for (int i = 0; i < T.length(); i++)
    {
        auto it = count.find(T[i]);
        if (it != count.end())
            it->second = it->second + 1;
        else
            count.insert(make_pair(T[i], 1));
    }
    unordered_map<char, queue<int>> lastPos;
    queue<int> window;
    int num = 0;
    for (size_t i = 0; i < S.length(); i++)
    {
        auto it = count.find(S[i]);
        if (it != count.end())
        {
            window.push(i);
            if (num == T.length())
            {
                lastPos[S[i]].pop();
                lastPos[S[i]].push(i);
                if (S[i] == S[window.front()])
                {
                    while (lastPos[S[window.front()]].front() != window.front())
                        window.pop();
                    if (i - window.front() + 1 < ret.length())
                        ret = S.substr(window.front(), i - window.front() + 1);
                }
            }
            else
            {
                auto itLast = lastPos.find(S[i]);
                if (itLast == lastPos.end())
                {
                    queue<int> q;
                    q.push(i);
                    lastPos.insert(make_pair(S[i], q));
                    num++;
                }
                else
                {
                    itLast->second.push(i);
                    if (itLast->second.size() > it->second)
                        itLast->second.pop();
                    else
                        num++;
                }
                if (num == T.length())
                {
                    while (lastPos[S[window.front()]].front() != window.front())
                        window.pop();
                    ret = S.substr(window.front(), i - window.front() + 1);
                }
            }
        }
    }
    return ret;
}

int main()
{
    cout << minWindow("bba", "ab") << endl;
    return 0;
}