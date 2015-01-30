#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    Solution()
    {
        for (size_t i = 0; i < 9; i++)
        {
            col.push_back(*(new set<char>()));
            row.push_back(*(new set<char>()));
            sqa.push_back(*(new set<char>()));
        }
    }
    void solveSudoku(vector<vector<char> > &board) {
        for (size_t i = 0; i < 9; i++)
        {
            for (size_t k = 0; k < 9; k++)
            {
                if (board[i][k] == '.')
                {
                    emptyCells.push_back(make_pair(i, k));
                }
                else
                {
                    char cur = board[i][k];
                    int s = i / 3 * 3 + k / 3;
                    col[k].insert(cur);
                    row[i].insert(cur);
                    sqa[s].insert(cur);
                }
            }
        }
        solve(board);
    }

    bool solve(vector<vector<char>>& board)
    {
        if (emptyCells.size() == 0)
            return true;
        pair<int, int> cell = emptyCells.back();
        emptyCells.pop_back();

        for (size_t i = 0; i < 9; i++)
        {
            char cur = '1' + i;
            int s = cell.first / 3 * 3 + cell.second / 3;
            if (col[cell.second].find(cur) == col[cell.second].end() &&
                row[cell.first].find(cur) == row[cell.first].end() &&
                sqa[s].find(cur) == sqa[s].end())
            {
                board[cell.first][cell.second] = cur;
                col[cell.second].insert(cur);
                row[cell.first].insert(cur);
                sqa[s].insert(cur);
                if (solve(board))
                    return true;
                col[cell.second].erase(cur);
                row[cell.first].erase(cur);
                sqa[s].erase(cur);
            }
        }
        board[cell.first][cell.second] = '.';
        emptyCells.push_back(cell);
        return false;
    }
private:
    vector<set<char>> col;
    vector<set<char>> row;
    vector<set<char>> sqa;
    vector<pair<int, int>> emptyCells;
};

int main()
{
    vector<vector<char>> board = {
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
    Solution s;
    s.solveSudoku(board);
    return 0;
}