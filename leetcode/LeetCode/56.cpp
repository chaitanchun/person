#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) 
    {
        vector<Interval> ret;
        map<int, int> interalMap;
        for (int i = 0; i < intervals.size(); i++)
        {
            auto it = interalMap.find(intervals[i].start);
            if (it != interalMap.end())
            {
                if (intervals[i].end > it->second)
                    it->second = intervals[i].end;
            }
            else
            {
                interalMap.insert(make_pair(intervals[i].start, intervals[i].end));
            }
        }
        for (auto it = interalMap.begin(); it != interalMap.end(); )
        {
            Interval inter(it->first, it->second);
            it++;
            while (it != interalMap.end() && it->first <= inter.end)
            {
                if (it->second > inter.end)
                    inter.end = it->second;
                it++;
            }
            ret.push_back(inter);
        }
        return ret;
    }
};
int main()
{
    vector<Interval> inters;
    Interval a(3, 6);
    inters.push_back(a);
    Interval b(1, 3);
    inters.push_back(b);
    Interval c(8, 10);
    inters.push_back(c);
    Interval d(15, 18);
    inters.push_back(d);
    Solution s;
    vector<Interval> ret = s.merge(inters);
    return 0;
}