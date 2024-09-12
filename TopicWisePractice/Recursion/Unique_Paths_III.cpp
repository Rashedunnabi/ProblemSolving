#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<vector<int>> &grid)
    {
        int cnt = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cnt += (grid[i][j] == 0);
        }
        return cnt == 0;
    }

    int func(int i, int j, int endx, int endy, vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if (i == endx && j == endy)
        {
            if (check(grid))
                return 1;
            else
                return 0;
        }
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == -1 || grid[i][j] == 1)
            return 0;

        int temp = grid[i][j];
        grid[i][j] = 1;
        int cnt = func(i + 1, j, endx, endy, grid);
        cnt += func(i - 1, j, endx, endy, grid);
        cnt += func(i, j + 1, endx, endy, grid);
        cnt += func(i, j - 1, endx, endy, grid);
        grid[i][j] = temp;
        return cnt;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int sx = -1, sy = -1, ex = -1, ey = -1, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    sx = i, sy = j;
                if (grid[i][j] == 2)
                    ex = i, ey = j;
            }
        }
        grid[sx][sy] = 5;
        return func(sx, sy, ex, ey, grid);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m)); // Fixed initialization of the 2D vector
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    Solution ob;
    cout << ob.uniquePathsIII(v) << '\n'; // Output the correct result
    return 0;
}
