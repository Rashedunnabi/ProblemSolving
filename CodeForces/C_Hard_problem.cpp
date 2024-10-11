#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<vector<int>> dp(n, vector<int>(2, INF));

    dp[0][0] = 0;
    dp[0][1] = v[0];

    for (int i = 1; i < n; i++)
    {
        string preRev = arr[i - 1];
        string curRev = arr[i];
        reverse(preRev.begin(), preRev.end());
        reverse(curRev.begin(), curRev.end());

        // without changing current string
        if (arr[i - 1] <= arr[i])
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (preRev <= arr[i])
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);

        // with changing the current string
        if (arr[i - 1] <= curRev)
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + v[i]);
        if (preRev <= curRev)
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + v[i]);
    }

    int ans = min(dp[n - 1][0], dp[n - 1][1]);
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}
