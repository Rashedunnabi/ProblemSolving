#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200010;
int ar[N], br[N];
ll dp[N];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        for (i = 1; i <= n; i++)
            cin >> ar[i];
        for (i = 1; i <= n; i++)
            cin >> br[i];

        ll sum = 0;
        for (i = n; i > 0; i--)
        {
            dp[i] = ar[i] + sum;
            sum += min(ar[i], br[i]);
        }

        ll ans = LONG_LONG_MAX;
        for (i = 1; i <= m; i++)
            ans = min(ans, dp[i]);

        for (i = 0; i <= n; i++)
            ar[i] = br[i] = dp[i] = 0;
        cout << ans << '\n';
    }
    return 0;
}