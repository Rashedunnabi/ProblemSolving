#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, i;
        cin >> n;
        vector<ll> l(n), r(n), c(n);
        for (ll &i : l)
            cin >> i;
        for (ll &i : r)
            cin >> i;
        for (ll &i : c)
            cin >> i;

        set<ll> ms(all(r));

        sort(rall(l));
        for (i = 0; i < n; i++)
        {
            auto it = ms.lower_bound(l[i]);
            r[i] = *it;
            ms.erase(it);
        }

        vector<ll> dif;
        for (int i = 0; i < n; i++)
        {
            ll df = r[i] - l[i];
            dif.push_back(df);
        }

        sort(rall(c));
        sort(all(dif));

        ll sum = 0ll;
        for (i = 0; i < n; i++)
        {
            ll x = dif[i] * 1LL * c[i];
            sum += x;
        }

        cout << sum << '\n';
    }
    return 0;
}