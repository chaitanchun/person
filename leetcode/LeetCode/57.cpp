#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        map<int, int> interalMap;
        interalMap.insert(make_pair(newInterval.start, newInterval.end));
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
        for (auto it = interalMap.begin(); it != interalMap.end();)
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
    Interval a(1, 2);
    Interval b(3, 5);
    Interval c(6, 7);
    Interval d(8, 10);
    Interval e(12, 16);
    Interval f(4, 9);
    vector<Interval> ints;
    Solution s;
    vector<Interval> ret = s.insert(ints, f);

    return 0;
}