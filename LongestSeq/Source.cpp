#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    unordered_map<int, int> start;
    unordered_map<int, int> end;
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    
    for (size_t i = 0; i < n; i++)
    {
        auto its = start.find(vec[i] + 1);
        auto ite = end.find(vec[i] - 1);
        if (its != start.end() && ite != end.end())
        {
            int tempstart = ite->second;
            int tempend = its->second;
            end.erase(ite);
            end[tempend] = tempstart;
            start.erase(its);
            start[tempstart] = tempend;
        }
        else if (its != start.end())
        {
            int tempend = its->second;
            start.erase(its);
            start.insert(make_pair(vec[i], tempend));
            auto it = end.find(tempend);
            if (it != end.end())
                it->second = vec[i];
        }
        else if (ite != end.end())
        {
            int tempstart = ite->second;
            end.erase(ite);
            end.insert(make_pair(vec[i], tempstart));
            auto it = start.find(tempstart);
            if (it != start.end())
                it->second = vec[i];
        }
        else
        {
            start.insert(make_pair(vec[i], vec[i]));
            end.insert(make_pair(vec[i], vec[i]));
        }
    }

    int max = 0;
    for (auto it = start.begin(); it != start.end(); it++)
    {
        if (it->second - it->first + 1 > max)
            max = it->second - it->first + 1;
    }
    cout << max << endl;
    return 0;
}