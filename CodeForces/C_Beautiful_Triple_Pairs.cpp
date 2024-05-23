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
        ll n;
        cin >> n;
        vector<ll> x(n);
        for (auto &xi : x)
        {
            cin >> xi;
        }

        map<array<ll, 2>, ll> cntab, cntac, cntbc;
        map<array<ll, 3>, ll> cntabc;
        ll ans = 0;
        for (ll i = 0; i + 3 <= n; ++i)
        {
            ll a = x[i], b = x[i + 1], c = x[i + 2];
            ans += cntab[{a, b}];
            ans += cntac[{a, c}];
            ans += cntbc[{b, c}];
            ans -= 3 * cntabc[{a, b, c}];

            cntab[{a, b}]++;
            cntac[{a, c}]++;
            cntbc[{b, c}]++;
            cntabc[{a, b, c}]++;
        }
        cout << ans << "\n";
    }

    return 0;
}