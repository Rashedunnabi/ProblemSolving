#include <bits/stdc++.h>
using namespace std;
#define int long long

// Recursive Dp with memoization
int func(int day, int last, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    // base case 1
    //  if (day == 0)
    //  {
    //      int maxi = 0;
    //      for (int i = 0; i < 3; i++)
    //      {
    //          if (i != last)
    //              maxi = max(maxi, v[day][i]);
    //      }
    //      return maxi;
    //  }

    // base case 2
    if (day < 0)
        return 0;

    if (dp[day][last] != -1)
        return dp[day][last];

    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
            ans = max(ans, func(day - 1, i, v, dp) + v[day][i]);
    }
    return dp[day][last] = ans;
}

// with recursive + memoization
int ninjaTraining1(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return func(n - 1, 3, points, dp);
}

// with tabulaton
int ninjaTraining2(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                    dp[day][last] = max(dp[day][last], dp[day - 1][task] + points[day][task]);
            }
        }
    }
    // return max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    // or
    return dp[n - 1][3];
}

// with space optimizations
int ninjaTraining3(int n, vector<vector<int>> &points)
{
    vector<int> dp(4);
    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max({points[0][0], points[0][1], points[0][2]});

    for (int day = 1; day < n; day++)
    {
        vector<int> cur(4);
        for (int last = 0; last < 4; last++)
        {
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                    cur[last] = max(cur[last], dp[task] + points[day][task]);
            }
        }
        dp = cur;
    }
    return dp[3];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    ninjaTraining3(n, points);
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(3));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
                cin >> v[i][j];
        }
        cout << ninjaTraining(n, v) << '\n';
    }
    return 0;
}