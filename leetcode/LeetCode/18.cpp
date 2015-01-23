#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target) {
    vector<vector<int>> ret;
    if (num.size() < 4)
        return ret;
    unordered_map<int, vector < int >> cache;
    sort(num.begin(), num.end());
    for (size_t i = 0; i < num.size() - 3;) 
    {
        for (size_t k = i + 1; k < num.size() - 2;)
        {
            int newTarget = target - num[i] - num[k];
            if (num[k + 1] + num[k + 2] <= newTarget && num.back() + num[num.size() - 2] >= newTarget)
            {
                float half = float(newTarget) / 2.0f;
                vector<int> pairs;
                int dec = k + 1;
                int inc = dec + 1;
                auto it = cache.find(newTarget);
                if (it != cache.end())
                {
                    for (size_t j = 0; j < it->second.size() - 2; j += 2)
                    {
                        vector<int> value = { num[i], num[k], it->second[j], it->second[j + 1] };
                        ret.push_back(value);
                    }
                    dec = it->second[it->second.size() - 2];
                    inc = it->second.back();
                    while (inc < num.size() && num[inc] == num[inc - 1])
                        inc++;
                    while (dec >= k + 1 && num[dec] == num[dec + 1])
                        dec--;
                }
                else
                {
                    for (size_t n = k + 1; n < num.size() - 1; n++)
                    {
                        if ((newTarget % 2 == 0 && num[n] == newTarget / 2) || (float(num[n]) < half && float(num[n + 1]) > half))
                        {
                            dec = n;
                            inc = n + 1;
                            break;
                        }
                    }
                }
                while (inc < num.size() && dec >= k + 1)
                {
                    int sum = num[inc] + num[dec];
                    if (sum > newTarget)
                    {
                        do
                        {
                            dec--;
                        } while (dec >= k + 1 && num[dec] == num[dec + 1]);
                    }
                    else if (sum < newTarget)
                    {
                        do
                        {
                            inc++;
                        } while (inc < num.size() && num[inc] == num[inc - 1]);
                    }
                    else
                    {
                        vector<int> value = { num[i], num[k], num[dec], num[inc] };
                        ret.push_back(value);
                        pairs.push_back(num[dec]);
                        pairs.push_back(num[inc]);
                        do
                        {
                            inc++;
                        } while (inc < num.size() && num[inc] == num[inc - 1]);
                        do
                        {
                            dec--;
                        } while (dec >= k + 1 && num[dec] == num[dec + 1]);

                    }
                }
                pairs.push_back(dec);
                pairs.push_back(inc);
                cache.insert(make_pair(newTarget, pairs));
            }
            do
            {
                k++;
            } while (k < num.size() - 2 && num[k] == num[k - 1]);
        }
        do
        {
            i++;
        } while (i < num.size() - 3 && num[i] == num[i - 1]);
    }
    return ret;
}

int main()
{
    vector<int> num = { -9, -2, 7, 6, -8, 5, 8, 3, -10, -7, 8, -8, 0, 0, 1, -8, 7 };
    vector<vector<int>> ret = fourSum(num, 4);
    return 0;
}