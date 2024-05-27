#include <bits/stdc++.h>
using namespace std;
#define int long long
const int NP = 1e15;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, x, i;
        cin >> n >> x;
        vector<int> cost(n), hp(n);
        for (i = 0; i < n; i++)
            cin >> cost[i] >> hp[i];

        int maxHp = accumulate(hp.begin(), hp.end(), 0LL), ans = 0;
        vector<int> dp(maxHp + 5, NP);
        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = maxHp; j >= hp[i]; j--)
            {
                if (dp[j - hp[i]] + cost[i] <= i * x)
                {
                    dp[j] = min(dp[j - hp[i]] + cost[i], dp[j]);
                    ans = max(ans, j);
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}