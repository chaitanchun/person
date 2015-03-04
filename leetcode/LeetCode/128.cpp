class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, int> start;
        unordered_map<int, int> end;
        unordered_set<int> checked;
        for (size_t i = 0; i < num.size(); i++)
        {
            if (checked.find(num[i]) != checked.end())
                continue;
            auto its = start.find(num[i] + 1);
            auto ite = end.find(num[i] - 1);
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
                start.insert(make_pair(num[i], tempend));
                auto it = end.find(tempend);
                if (it != end.end())
                    it->second = num[i];
            }
            else if (ite != end.end())
            {
                int tempstart = ite->second;
                end.erase(ite);
                end.insert(make_pair(num[i], tempstart));
                auto it = start.find(tempstart);
                if (it != start.end())
                    it->second = num[i];
            }
            else
            {
                start.insert(make_pair(num[i], num[i]));
                end.insert(make_pair(num[i], num[i]));
            }
            checked.insert(num[i]);
        }

        int max = 0;
        for (auto it = start.begin(); it != start.end(); it++)
        {
            if (it->second - it->first + 1 > max)
                max = it->second - it->first + 1;
        }
        return max;

    }
};