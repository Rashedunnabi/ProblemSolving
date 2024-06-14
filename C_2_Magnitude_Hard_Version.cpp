#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int MAXN = 1e6 + 5;
int arr[MAXN], dp[MAXN], dp2[MAXN], dp3[MAXN], dp4[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        dp[1] = max(arr[1], abs(arr[1]));
        dp2[1] = min(arr[1], abs(arr[1]));
        dp3[1] = dp4[1] = (arr[1] >= 0) ? 2 : 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = max({dp[i - 1] + arr[i], abs(dp[i - 1] + arr[i]), dp2[i - 1] + arr[i], abs(dp2[i - 1] + arr[i])});
            dp3[i] = 0;
            if (dp[i] == abs(dp[i - 1] + arr[i]))
                dp3[i] = (dp3[i] + dp3[i - 1]) % MOD;
            if (dp[i] == dp[i - 1] + arr[i])
                dp3[i] = (dp3[i] + dp3[i - 1]) % MOD;
            if (dp[i - 1] != dp2[i - 1])
            {
                if (dp[i] == dp2[i - 1] + arr[i])
                    dp3[i] = (dp3[i] + dp4[i - 1]) % MOD;
                if (dp[i] == abs(dp2[i - 1] + arr[i]))
                    dp3[i] = (dp3[i] + dp4[i - 1]) % MOD;
            }

            dp2[i] = min({dp[i - 1] + arr[i], abs(dp[i - 1] + arr[i]), dp2[i - 1] + arr[i], abs(dp2[i - 1] + arr[i])});
            dp4[i] = 0;
            if (dp2[i] == abs(dp[i - 1] + arr[i]))
                dp4[i] = (dp4[i] + dp3[i - 1]) % MOD;
            if (dp2[i] == dp[i - 1] + arr[i])
                dp4[i] = (dp4[i] + dp3[i - 1]) % MOD;
            if (dp[i - 1] != dp2[i - 1])
            {
                if (dp2[i] == dp2[i - 1] + arr[i])
                    dp4[i] = (dp4[i] + dp4[i - 1]) % MOD;
                if (dp2[i] == abs(dp2[i - 1] + arr[i]))
                    dp4[i] = (dp4[i] + dp4[i - 1]) % MOD;
            }
        }

        cout << dp3[n] << "\n";
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp2[i] = dp3[i] = dp4[i] = 0;
        }
    }

    return 0;
}
