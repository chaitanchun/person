#include <iostream>
#include <vector>
using namespace std;


bool solve(vector<vector<char>>& board, vector<pair<int, int>> & emptyCells)
{
    if (emptyCells.size() == 0)
        return true;
    pair<int, int> cell = emptyCells.back();
    emptyCells.pop_back();

    //check posiable number
    vector<bool> num = { true, true, true, true, true, true, true, true, true };
    for (size_t k = 0; k < 9 && k != cell.second; k++)
        if (board[cell.first][k] != '.')
            num[board[cell.first][k] - '1'] = false;
    for (size_t k = 0; k < 9 && k != cell.first; k++)
        if (board[k][cell.second] != '.')
            num[board[k][cell.second] - '1'] = false;
    int r = cell.first / 3;
    int c = cell.second / 3;
    for (size_t k = 0; k < 3; k++)
        for (size_t n = 0; n < 3; n++)
            if (board[k + r * 3][n + c * 3] != '.')
                num[board[k + r * 3][n + c * 3] - '1'] = false;
    for (size_t i = 0; i < 9; i++)
    {
        if (num[i])
        {
            board[cell.first][cell.second] = '1' + i;
            if (solve(board, emptyCells))
                return true;
        }
    }
    board[cell.first][cell.second] = '.';
    emptyCells.push_back(cell);
    return false;
}

void solveSudoku(vector<vector<char> > &board)
{
    vector<pair<int, int>> emptyCells;
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t k = 0; k < 9; k++)
        {
            if (board[i][k] == '.')
                emptyCells.push_back(make_pair(i, k));
        }
    }
    solve(board, emptyCells);
}

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
    solveSudoku(board);
    return 0;
}