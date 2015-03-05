#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) 
    {
        int n = num.size() / 2;
        if (n == 0)
            return num[0];
        unordered_map<int, int> hashTable;
        for (size_t i = 0; i < num.size(); i++)
        {
            auto it = hashTable.find(num[i]);
            if (it != hashTable.end())
            {
                it->second = it->second + 1;
                if (it->second > n)
                    return it->first;
            }
            else
            {
                hashTable.insert(make_pair(num[i], 1));
            }
        }
    }
};

int main()
{
    return 0;
}