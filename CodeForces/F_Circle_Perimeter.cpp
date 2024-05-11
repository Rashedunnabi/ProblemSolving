#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll value(ll r, ll i)
{
    return sqrt(r * r - i * i - 1);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll r, ans = 0;
        cin >> r;
        for (ll i = 0; i <= r; i++)
        {
            ans += value(r + 1, i) - value(r, i);
        }
        cout << ans * 4 << '\n';
    }
    return 0;
}