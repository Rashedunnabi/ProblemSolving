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
        ll n, i;
        cin >> n;

        vector<ll> a(n), b(n + 1);
        for (ll &i : a)
            cin >> i;
        for (ll &i : b)
            cin >> i;

        ll lastDif = INT_MAX;
        ll ans = 0;
        for (i = 0; i < n; i++)
        {
            ll dif = abs(a[i] - b[i]);
            ans += dif;

            if (b.back() <= max(a[i], b[i]) && b.back() >= min(a[i], b[i]))
                lastDif = 0;
            else
                lastDif = min(lastDif, min(abs(b.back() - a[i]), abs(b.back() - b[i])));
        }
        ans += lastDif + 1;
        cout << ans << '\n';
    }
    return 0;
}