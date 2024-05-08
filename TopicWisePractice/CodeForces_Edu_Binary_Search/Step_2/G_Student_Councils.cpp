#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll mid, vector<ll> &arr, ll k)
{
    ll need = k * 1LL * mid;
    ll cnt = 0;
    for (ll val : arr)
        cnt += min(val, mid);
    return cnt >= need;
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    ll k, n, i;
    cin >> k >> n;

    vector<ll> v(n);
    for (ll &i : v)
        cin >> i;

    ll lo = 0, hi = 35 * 1e9, mid;
    while (hi - lo > 1)
    {
        mid = lo + (hi - lo) / 2;
        if (check(mid, v, k))
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << '\n';
}