#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word)
    {
        mWord = word;
        mBoard = board;
        for (size_t i = 0; i < mBoard.size(); i++)
        {
            vector<bool> temp(mBoard[i].size(), false);
            used.push_back(temp);
        }
        bool ret = false;
        for (size_t i = 0; i < mBoard.size(); i++)
        {
            for (size_t k = 0; k < mBoard[i].size(); k++)
            {
                if (search(i, k, 0))
                    return true;
            }
        }
        return false;
    }
private:
    bool search(int row, int col, int index)
    {
        if (index == mWord.length())
            return true;
        if (row < 0 || row >= mBoard.size() || col < 0 || col >= mBoard[row].size())
            return false;
        if (!used[row][col] && mBoard[row][col] == mWord[index])
        {
            used[row][col] = true;
            //up
            if (search(row - 1, col, index + 1))
                return true;
            //down
            if (search(row + 1, col, index + 1))
                return true;
            //left
            if (search(row, col - 1, index + 1))
                return true;
            //right
            if (search(row, col + 1, index + 1))
                return true;
            used[row][col] = false;
        }
        return false;
    }

private:
    vector<vector<bool>> used;
    string mWord;
    vector<vector<char>> mBoard;
};

int main()
{
    vector<char> a = { 'A', 'B', 'C', 'D' };
    vector<char> b = { 'S', 'F', 'C', 'S' };
    vector<char> c = { 'A', 'D', 'E', 'E' };
    vector<vector<char>> board = { a, b, c };
    Solution s;
    //cout << s.exist(board, "ABCCED") << endl;
    //cout << s.exist(board, "SEE") << endl;
    cout << s.exist(board, "ABCB") << endl;
    return 0;
}