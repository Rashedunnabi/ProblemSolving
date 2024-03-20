#include <bits/stdc++.h>
using namespace std;

void solution()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> ar(n), br(n), cr(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &ar[i]);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &br[i]);
        cr[i] = min(br[i], ar[i]);
    }

    vector<long long> dp(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
            dp[i] = cr[i];
        else
            dp[i] = dp[i + 1] + cr[i];
    }

    long long ans = LONG_LONG_MAX;
    for (int i = 0; i < m; i++)
    {
        long long sum = ar[i] + (i + 1 < n ? dp[i + 1] : 0);
        ans = min(ans, sum);
    }

    printf("%lld\n", ans);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        solution();
    }
    return 0;
}
