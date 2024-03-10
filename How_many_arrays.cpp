#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 998244353

ll bin_exp(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1)
            res = (res * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

void solve()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> primes;
    for (ll i = 2; i * i <= k; ++i)
    {
        if (k % i == 0)
        {
            ll cnt = 0;
            while (k % i == 0)
            {
                cnt++;
                k /= i;
            }
            primes.push_back(cnt);
        }
    }
    if (k > 1)
        primes.push_back(1);

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll temp = 1;
        for (auto el : primes)
        {
            temp *= (bin_exp(el + 1, i) - bin_exp(el, i) + MOD) % MOD;
            temp %= MOD;
        }
        ans += temp;
        ans %= MOD;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
