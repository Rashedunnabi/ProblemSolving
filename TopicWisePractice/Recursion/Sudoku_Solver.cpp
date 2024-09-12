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
    bool solver(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (check(ch, i, j, board))
                        {
                            board[i][j] = ch;
                            if (solver(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        bool flag = solver(board);
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
    ob.solveSudoku(arr);
    for (auto v : arr)
    {
        for (auto val : v)
            cout << val << ' ';
        cout << '\n';
    }
    cout << '\n';
    return 0;
}