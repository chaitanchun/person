#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) 
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
        return ret;
    }

private:
    void solve(int n)
    {
        if (n == 0)
        {
            num++;
            vector<string> solu;
            for (size_t i = 0; i < board.size(); i++)
            {
                string retrow;
                for (size_t k = 0; k < board.size(); k++)
                {
                    if (board[i][k])
                        retrow.push_back('Q');
                    else
                        retrow.push_back('.');
                }
                solu.push_back(retrow);
            }
            ret.push_back(solu);
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
    vector<vector<string>> ret;
    vector<vector<bool>> board;
    int num;
};
int main()
{
    Solution s;
    s.solveNQueens(4);
    return 0;
}