#include <iostream>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        for (int i = 0; i < n; i++)
            if (A[i] == target)
                return true;
        return false;
    }
};


int main()
{
    int A[] = { 2, 2, 2, 0, 2, 2 };
    Solution s;
    int re = s.search(A, 6, 0);
    return 0;
}