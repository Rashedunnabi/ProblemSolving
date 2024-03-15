#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void solution()
{
    ll n, m, k, i;
    cin >> n >> m >> k;
    vector<ll> a(n), d(m), f(k);
    for (ll &i : a)
        cin >> i;
    for (ll &i : d)
        cin >> i;
    for (ll &i : f)
        cin >> i;

    vector<pair<ll, ll>> dif;
    for (i = 0; i < n - 1; i++)
    {
        dif.push_back({a[i + 1] - a[i], i});
    }

    sort(rall(dif)), sort(all(d)), sort(all(f));

    ll maxi = dif[0].first, id = dif[0].second, res = 0;
    if (n > 2)
        res = dif[1].first;

    for (i = 0; i < m; i++)
    {
        ll l = a[id], r = a[id + 1], mid;
        mid = (l + r) / 2;

        ll it = lower_bound(f.begin(), f.end(), mid - d[i]) - f.begin();

        for (ll j = max(0ll, it - 5); j < min(k, it + 5); j++)
        {
            if (d[i] + f[j] <= r && d[i] + f[j] >= l)
            {
                ll temp = max(a[id + 1] - d[i] - f[j], d[i] + f[j] - a[id]);
                maxi = min(maxi, temp);
            }
        }
    }
    cout << max(maxi, res) << '\n';
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