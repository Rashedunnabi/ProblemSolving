#include <bits/stdc++.h>
using namespace std;
#define int long long

int func(int i, int j, string s, vector<vector<int>> &dp)
{
    if (i >= j)
        return i == j;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if (s[i] == s[j])
        ans += 1 + func(i + 1, j - 1, s, dp);
    ans += func(i + 1, j, s, dp) + func(i, j - 1, s, dp) - func(i + 1, j - 1, s, dp);
    return dp[i][j] = ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        cout << "Case " << tc << ": ";
        string s;
        cin >> s;
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        cout << func(0, n - 1, s, dp) << '\n';
    }
    return 0;
}