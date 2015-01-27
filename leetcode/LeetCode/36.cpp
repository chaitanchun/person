#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool isValidSudoku(vector<vector<char> > &board) 
{
    for (size_t i = 0; i < 9; i++)
    {
        unordered_set<char> s;
        for (size_t k = 0; k < 9; k++)
        {
            if (board[i][k] != '.')
            {
                auto it = s.find(board[i][k]);
                if (it != s.end())
                    return false;
                else
                    s.insert(board[i][k]);
            }
        }
    }
    for (size_t i = 0; i < 9; i++)
    {
        unordered_set<char> s;
        for (size_t k = 0; k < 9; k++)
        {
            if (board[k][i] != '.')
            {
                auto it = s.find(board[k][i]);
                if (it != s.end())
                    return false;
                else
                    s.insert(board[k][i]);
            }
        }
    }
    for (size_t i = 0; i < 9; i++)
    {
        unordered_set<char> s;
        int c = i % 3;
        int r = i / 3;
        for (size_t k = 0; k < 3; k++)
            for (size_t n = 0; n < 3; n++)
            {
                if (board[k + r * 3][n + c * 3] != '.')
                {
                    auto it = s.find(board[k + r * 3][n + c * 3]);
                    if (it != s.end())
                        return false;
                    else
                        s.insert(board[k + r * 3][n + c * 3]);
                }
            }
    }
    return true;
}

int main()
{
    vector<vector<char>> board = { 
        { '.', '.', '5', '.', '.', '.', '.', '.', '6' },
        { '.', '.', '.', '.', '1', '4', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '.', '.', '.', '.' },
        { '.', '.', '.', '.', '.', '9', '2', '.', '.' },
        { '5', '.', '.', '.', '.', '2', '.', '.', '.' },
        { '6', '.', '.', '.', '.', '.', '.', '3', '.' },
        { '.', '.', '.', '5', '4', '.', '.', '.', '.' },
        { '3', '.', '.', '.', '.', '.', '4', '2', '.' },
        { '.', '.', '.', '2', '7', '.', '6', '.', '.' } };
    cout << isValidSudoku(board) << endl;
    return 0;
}