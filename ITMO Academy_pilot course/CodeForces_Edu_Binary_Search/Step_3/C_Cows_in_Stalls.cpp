// its the another version of agressive cows problem in spoj

#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool check(ll mid, ll k, vector<ll> &v)
{
    ll i, n = v.size(), prev = v[0], cnt = 1;
    for (i = 1; i < n; i++)
    {
        if (v[i] - prev >= mid)
        {
            cnt++;
            prev = v[i];
        }
    }
    return cnt >= k;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    ll n, k, i;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll &i : v)
        cin >> i;

    ll lo = 0, hi = 2e9 + 100, mid;
    while (hi - lo > 1)
    {
        mid = lo + (hi - lo) / 2;
        if (check(mid, k, v))
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << '\n';
    return 0;
}