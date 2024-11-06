#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n, int m, vector<vector<bool>> &vis)
{
    return i >= 0 && j >= 0 && i < n && j < m && !vis[i][j];
}
bool func(int i, int j, int k, vector<vector<bool>> &vis, vector<vector<char>> &board, string &word)
{
    int n = board.size(), m = board[0].size();

    if (k == word.length())
        return true;
    if (!isValid(i, j, n, m, vis) || board[i][j] != word[k])
        return false;

    bool flag = 0;
    vis[i][j] = true;

    flag |= func(i, j + 1, k + 1, vis, board, word);
    flag |= func(i + 1, j, k + 1, vis, board, word);
    flag |= func(i, j - 1, k + 1, vis, board, word);
    flag |= func(i - 1, j, k + 1, vis, board, word);

    vis[i][j] = false;
    return flag;
}
bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size(), m = board[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m));
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            flag |= func(i, j, 0, vis, board, word);
    }
    return flag;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> v(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> v[i][j];
        }

        cout << exist(v, "1543") << '\n';
    }
    return 0;
}