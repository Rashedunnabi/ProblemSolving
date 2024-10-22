#include <bits/stdc++.h>
using namespace std;

int func(int i, int k, vector<int> &h, vector<int> &dp)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int cost = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (i - j < 0)
            break;
        cost = min(cost, func(i - j, k, h, dp) + abs(h[i] - h[i - j]));
    }
    return dp[i] = cost;
}
int minimizeCost(int n, int k, vector<int> &h) // with memoization
{
    vector<int> dp(n + 1, -1);
    return func(n - 1, k, h, dp);
}
// with tabulation
int minimizeCost2(int n, int k, vector<int> &h)
{
    vector<int> dp(n);
    for (int i = 1; i < n; i++)
    {
        int cost = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j < 0)
                break;
            cost = min(cost, dp[i - j] + abs(h[i] - h[i - j]));
        }
        dp[i] = cost;
    }
    return dp[n - 1];
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << minimizeCost(n, k, arr) << '\n';

    return 0;
}