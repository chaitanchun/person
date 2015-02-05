#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int totalNQueens(int n)
    {
        col.assign(n, false);
        leftCross.assign(2 * n - 1, false);
        rightCross.assign(2 * n - 1, false);
        num = 0;
        for (size_t i = 0; i < n; i++)
        {
            vector<bool> temp(n, false);
            board.push_back(temp);
        }
        solve(n);
        return num;
    }

private:
    void solve(int n)
    {
        if (n == 0)
        {
            num++;
            return;
        }

        int row = board.size() - n;
        for (size_t k = 0; k < board.size(); k++)
        {
            if (!col[k] && !leftCross[board.size() - 1 - k + row] && !rightCross[row + k])
            {
                board[row][k] = true;
                col[k] = true;
                leftCross[board.size() - 1 - k + row] = true;
                rightCross[row + k] = true;
                solve(n - 1);
                rightCross[row + k] = false;
                leftCross[board.size() - 1 - k + row] = false;
                col[k] = false;
                board[row][k] = false;
            }
        }
    }
private:
    vector<bool> col;
    vector<bool> leftCross;
    vector<bool> rightCross;
    vector<vector<bool>> board;
    int num;
};
int main()
{
    Solution s;
    s.totalNQueens(4);
    return 0;
}