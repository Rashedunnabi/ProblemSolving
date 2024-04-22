#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 100000007;

void solution()
{
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i)
        cin >> coins[i];

    vector<int> dp(k + 1, 0);
    dp[0] = 1;

    for (int j = 0; j < n; ++j)
    {
        for (int i = coins[j]; i <= k; ++i)
        {
            dp[i] += dp[i - coins[j]];
            dp[i] %= MOD;
        }
        // for (int i = 0; i <= k; i++)
        //     cout << dp[i] << ' ';
        // cout << '\n';
    }
    cout << dp[k] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        solution();
    }
    return 0;
}