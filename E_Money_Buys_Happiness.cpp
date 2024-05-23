#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
const ll N = 1e5 + 7;
ll dp[55][N];
ll cost[55], hp[55];
ll m, x;

ll func(ll i, ll amount)
{
    if (amount == 0)
        return 0;
    if (i < 0)
        return 1e15;
    if (dp[i][amount] != -1)
        return dp[i][amount];

    ll ans = func(i - 1, amount);
    if (amount - hp[i] >= 0)
        ans = min(ans, func(i - 1, amount - hp[i]) + cost[i]);

    return dp[i][amount] = ans;
}

void solution()
{

    cin >> m >> x;
    for (ll i = 1; i <= m; i++)
        cin >> cost[i] >> hp[i];

    memset(dp, -1, sizeof(dp));

    for (ll i = N; i >= 0; i--)
    {
        if (func(m, i) <= (i + 1) * x)
        {
            cout << i << '\n';
            break;
        }
    }
}

int main()
{
    Faster;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}