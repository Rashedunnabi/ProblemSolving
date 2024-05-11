#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool check(ll mid, ll n, ll k, vector<ll> &v)
{
    ll cnt = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > mid)
            return false;

        if (sum + v[i] <= mid)
            sum += v[i];
        else
        {
            cnt++;
            sum = v[i];
        }
    }
    return cnt <= k;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll n, k, i;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll &i : v)
        cin >> i;

    ll lo = 0, mid, hi = accumulate(v.begin(), v.end(), 0LL) + 100;
    while (hi - lo > 1)
    {
        mid = lo + (hi - lo) / 2;
        if (check(mid, n, k, v))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << '\n';

    return 0;
}