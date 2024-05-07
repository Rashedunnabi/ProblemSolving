#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct assistant
{
    ll t, z, y;
};

bool check(ll mid, ll n, ll m, assistant *ar)
{
    if (mid < 0)
        return false;

    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        ll t = ar[i].t, z = ar[i].z, y = ar[i].y;
        ll x = (t * z) + y;
        ll div = mid / x;
        ll newValue = mid - (div * y);
        if (mid % x > (t * z))
            newValue -= ((mid % x) - (t * z));
        cnt += (newValue / t);
    }
    return cnt >= m;
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    ll m, n, i;
    cin >> m >> n;

    assistant ar[n];
    for (i = 0; i < n; i++)
        cin >> ar[i].t >> ar[i].z >> ar[i].y;

    ll lo = -1, hi = 1e9, mid;
    while (hi - lo > 1)
    {
        mid = lo + (hi - lo) / 2;
        if (check(mid, n, m, ar))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << '\n';
    for (i = 0; i < n; i++)
    {
        ll t = ar[i].t, z = ar[i].z, y = ar[i].y;
        ll x = (t * z) + y;
        ll div = hi / x;
        ll newValue = hi - (div * y);
        if (hi % x > (t * z))
            newValue -= ((hi % x) - (t * z));
        ll val = (newValue / t);
        ll mn = min(val, m);
        cout << mn << ' ';
        m -= mn;
    }
    cout << '\n';

    return 0;
}