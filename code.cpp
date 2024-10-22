#include <bits/stdc++.h>
using namespace std;

int maximumChocolates(int n, int m, vector<vector<int>> &grid)
{
    int dp[n][m][m];
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == j)
                dp[n - 1][i][j] = grid[n - 1][j];
            else
                dp[n - 1][i][j] = grid[n - 1][i] + grid[n - 1][j];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = INT_MIN;
                for (int di = -1; di <= 1; di++)
                {
                    for (int dj = -1; dj <= 1; dj++)
                    {
                        int newJ1 = j1 + di;
                        int newJ2 = j2 + dj;
                        if (newJ1 >= 0 && newJ2 >= 0 && newJ1 < m &&
                            newJ2 < m) {
                          int currentValue;
                          if (j1 == j2)
                            currentValue = grid[i][j1];
                          else
                            currentValue = grid[i][j1] + grid[i][j2];

                          currentValue += dp[i + 1][newJ1][newJ2];
                          maxi = max(maxi + 0LL, currentValue);
                        }
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}
