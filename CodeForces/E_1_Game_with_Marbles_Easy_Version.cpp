#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void solution()
{
    ll n, i;
    cin >> n;

    ll a[n], b[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];
    vector<pair<ll, ll>> v;
    for (i = 0; i < n; i++)
    {
        v.push_back({a[i] + b[i], i});
    }

    sort(rall(v));
    ll ans = 0;
    for (i = 0; i < n; i++)
    {
        ll j = v[i].second;
        if (i & 1) // bob
        {
            ans -= b[j] - 1;
        }
        else // alice
        {
            ans += a[j] - 1;
        }
    }
    cout << ans << '\n';
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