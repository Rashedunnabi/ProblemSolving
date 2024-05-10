#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long power(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll findHigh(ll w, ll h, ll n)
{
    ll ans = 0;
    for (ll i = 0; i <= 60; i++)
    {
        ll value = power(2LL, i);

        ll x = value / h;
        ll y = value / w;

        if (x * 1LL * y >= n)
        {
            ans = value;
            break;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    ll w, h, n;
    cin >> w >> h >> n;

    ll hi = findHigh(w, h, n) + 10, lo = 1, mid;

    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;

        ll x = mid / h;
        ll y = mid / w;

        if (x * 1LL * y >= n)
            hi = mid;
        else
            lo = mid;
    }

    ll x = lo / h, y = lo / w;
    if (x * 1LL * y >= n)
        cout << lo << '\n';
    else
        cout << hi << '\n';

    return 0;
}