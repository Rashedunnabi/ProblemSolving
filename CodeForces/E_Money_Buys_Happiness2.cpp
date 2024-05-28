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
        int n, x, ans = 0;
        cin >> n >> x;
        vector<int> cost(n + 2), hp(n + 2);
        for (int i = 1; i <= n; i++)
            cin >> cost[i] >> hp[i];
        int maxSum = accumulate(hp.begin(), hp.end(), 0LL);

        vector<int> dp(maxSum + 10, NP);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = maxSum; j >= hp[i]; j--)
            {
                if (dp[j - hp[i]] + cost[i] <= (i - 1) * x)
                {
                    dp[j] = min(dp[j], dp[j - hp[i]] + cost[i]);
                    ans = max(ans, j);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}