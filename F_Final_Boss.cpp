#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll a[200000 + 5], c[200000 + 5];
ll h2;
ll t, n, h, l, r, res;

long long power(ll A, ll B, ll P)
{
    long long ress = 1;
    while (B > 0)
    {
        if (B % 2 == 1)
        {
            ress = ress * A;
        }
        B = B >> 1;
        A = A * A;
    }
    return ress % P;
}

void primeFactors(ll ww)
{
    while (ww % 2 == 0)
    {
        ww = ww / 2;
    }
    for (ll ii = 3; ii <= sqrt(ww); ii = ii + 2)
    {
        while (ww % ii == 0)
        {
            ww = ww / ii;
        }
    }
}

bool mara(ll sa, ll gk, ll n)
{
    ll ty = 0;
    for (ll j = 0; j < n; j++)
    {
        ll kk = sa + c[j];
        ll ds = (kk - 1LL) / c[j];
        ll kk2 = ds * a[j];
        ty = ty + kk2;
    }
    return ty >= gk;
}

void solve()
{
    cin >> h >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (ll i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    l = 0, r = 1;

    for (ll i = 0; i <= 63; i++)
    {
        h2 = powl(2, i);
        if (mara(h2, h, n))
        {
            r = h2;
            break;
        }
    }

    while (r - l > 1)
    {
        h2 = l + (r - l) / 2;
        if (mara(h2, h, n))
        {
            r = h2;
        }
        else
        {
            l = h2;
        }
    }

    res = r;
    cout << res << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(0);

    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
