#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solution()
{
    ll n, m, MOD = 998244353;
    cin >> n >> m;
    ll x = (n + 1) / 2;
    ll y = (m + 1) / 2;
    ll k = max(max(x - 1, n - x), max(y - 1, m - y));
    ll up_x = min(n, k + 1);
    ll low_x = max(1ll, n - k);
    ll up_y = min(m, k + 1);
    ll low_y = max(1ll, m - k);
    ll ans = ((up_x + low_x) * (up_x - low_x + 1) / 2 % MOD) * ((up_y + low_y) * (up_y - low_y + 1) / 2 % MOD) % MOD;
    cout << ans << '\n';
}

int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}