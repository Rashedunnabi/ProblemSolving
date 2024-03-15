#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, x, m;
vector<vector<ll>> dp;
ll f(ll i, ll sum, vector<ll> &v, ll target)
{
    if (i == n)
        return (target == sum) ? 0 : 1e16;
    if (dp[i][sum] != -1)
        return dp[i][sum];
    ll ans = v[i] + f(i + 1, (sum + v[i]) % x, v, target);

    ans = min(ans, f(i + 1, sum, v, target));
    return dp[i][sum] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll k, ans;
        cin >> n >> x >> k;
        vector<ll> v(n);
        for (auto &i : v)
            cin >> i;

        if (k % x == 0)
        {
            cout << (k / x) << endl;
            continue;
        }

        dp.assign(n, vector<ll>(x, -1));
        ll target = x - (k % x);
        ll res = f(0, 0, v, target);
        (res >= 1e16) ? ans = -1 : ans = (res + k) / x;
        cout << ans << '\n';
    }
    return 0;
}
