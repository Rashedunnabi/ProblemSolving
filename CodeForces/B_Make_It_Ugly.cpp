// 9876543210...???
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl "\n"

long long power(long long A, long long B)
{
    if (B == 0)
        return 1;
    long long ress = power(A, B / 2);
    if (B % 2)
        return ress * ress * A;
    else
        return ress * ress;
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

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    set<ll> mp;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        mp.insert(v[i]);
    }
    if (mp.size() == 1)
    {
        cout << -1 << endl;
    }
    else
    {
        ll cnt = 0, ans = n;
        for (ll i = 0; i < n; i++)
        {
            if (v[i] == v[0])
                cnt++;
            else
            {
                ans = min(ans, cnt);
                cnt = 0;
            }
        }
        ans = min(ans, cnt);
        cout << ans << endl;
    }
}

int main()
{

    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
