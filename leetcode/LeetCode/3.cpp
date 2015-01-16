#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> letters;
    int ret = 0;
    int curr = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        unordered_map<char, int>::iterator it = letters.find(s[i]);
        if (it == letters.end())
        {
            letters.insert(make_pair(s[i], i));
            curr++;
        }
        else
        {
            if (curr > ret)
                ret = curr;
            for (size_t k = i - curr; k < it->second; k++)
                letters.erase(s[k]);
            curr = i - it->second;
            it->second = i;
        }
    }
    return curr > ret ? curr : ret;
}

int main()
{
    cout << lengthOfLongestSubstring("qopubjguxhxdipfzwswybgfylqvjzhar") << endl;
    cout << lengthOfLongestSubstring("bbbbbbb") << endl;
    return 0;
}