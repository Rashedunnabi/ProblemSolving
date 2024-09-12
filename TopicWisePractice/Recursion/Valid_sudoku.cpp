#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(char ch, int row, int col, vector<vector<char>> &board)
    {
        bool flag = 1;
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == ch)
                flag = 0;
            if (board[row][i] == ch)
                flag = 0;

            int newRow, newCol;
            newRow = ((row / 3) * 3) + (i / 3);
            newCol = ((col / 3) * 3) + (i % 3);
            if (board[newRow][newCol] == ch)
                flag = 0;
        }
        return flag;
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                char ch = board[i][j];
                board[i][j] = '.';
                if (!check(ch, i, j, board))
                    return false;
                board[i][j] = ch;
            }
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n = 9;
    vector<vector<char>> arr(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            arr[i].push_back(x);
        }
    }

    Solution ob;
    cout << ob.isValidSudoku(arr) << '\n';

    return 0;
}