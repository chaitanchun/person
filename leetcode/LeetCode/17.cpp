#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public: 
    Solution()
    {
        num.insert(make_pair('2', "abc"));
        num.insert(make_pair('3', "def"));
        num.insert(make_pair('4', "ghi"));
        num.insert(make_pair('5', "jkl"));
        num.insert(make_pair('6', "mno"));
        num.insert(make_pair('7', "pqrs"));
        num.insert(make_pair('8', "tuv"));
        num.insert(make_pair('9', "wxyz"));
    }
    vector<string> letterCombinations(string digits) { 
        vector<string> ret;
        ret.push_back("");
        if (digits.length() == 0)
            return ret;
        for (size_t i = 0; i < digits.length(); i++)
        {
            auto it = num.find(digits[i]);
            if (it != num.end())
            {
                vector<string> value;
                for (size_t k = 0; k < ret.size(); k++)
                    for (size_t n = 0; n < it->second.length(); n++)
                        value.push_back(ret[k] + it->second.substr(n, 1));
                ret = value;
            }
        }
        return ret;
    }
private:
    unordered_map<char, string> num;
};

int main()
{
    Solution s;
    vector<string> ret = s.letterCombinations("23");
    return 0;
}