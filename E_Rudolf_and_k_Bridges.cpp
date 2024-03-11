#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int mod = 1e9 + 7;
const int N = 2e5 + 7;

int minTotalCost(vector<vector<int>> &depths, int n, int m, int k, int d)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX / 2));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int maxDepth = 0;
            for (int r = 1; r <= k && i - r >= 0; r++)
            {
                maxDepth = max(maxDepth, depths[i - r][0]);
                if (j - r < 0)
                    continue;
                maxDepth = max(maxDepth, depths[i - r][m - 1]);
                for (int l = 0; l <= j - r + 1; ++l)
                {
                    dp[i][j] = min(dp[i][j], dp[i - r][l] + maxDepth);
                }
            }
        }
    }
    int minCost = INT_MAX;
    for (int j = 1; j <= n; j++)
    {
        minCost = min(minCost, dp[n][j]);
    }
    return minCost;
}

void solution()
{
    int n, m, k, d, i, j;
    cin >> n >> m >> k >> d;
    vector<vector<int>> depths(n, vector<int>(m));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> depths[i][j];
        }
    }

    int result = minTotalCost(depths, n, m, k, d);
    cout << result << '\n';
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}