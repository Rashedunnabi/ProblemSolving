#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll n, i, mod = 1e9 + 7;
        cin >> n;

        vector<ll> v(n);
        for (ll &i : v)
            cin >> i;

        sort(v.begin(), v.end());
        ll ans = v[0];

        for (i = 1; i < n; i++)
        {
            if (ans * 1ll * v[i] >= ans + v[i])
                ans *= v[i];
            else
                ans += v[i];
            ans %= mod;
        }
        cout << ans << '\n';
    }
    return 0;
}