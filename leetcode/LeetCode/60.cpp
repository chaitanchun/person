#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k)
    {
        vector<char> selected;
        for (int i = 0; i < n; i++)
            selected.push_back('1' + i);
        string ret;
        int num = 1;
        for (int i = 2; i <= n; i++)
            num *= i;
        for (int i = 0; i < n; i++)
        {
            int cur = 0;
            num /= (n - i);
            while (k > num)
            {
                k -= num;
                cur++;
            }
            ret.push_back(selected[cur]);
            selected.erase(selected.begin() + cur);
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.getPermutation(3, 5) << endl;
    cout << s.getPermutation(3, 1) << endl;
    cout << s.getPermutation(3, 6) << endl;
    cout << s.getPermutation(3, 3) << endl;
    return 0;
}