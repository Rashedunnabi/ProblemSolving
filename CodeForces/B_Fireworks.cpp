#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"

ll lcm(ll a, ll b)
{
    ll gc = __gcd(a, b);
    ll lc = a * 1LL * b / gc;
    return lc;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        ll lc = lcm(a, lcm(b, c));
        // cout << lc << '\n';

        ll ans = 2 + (c / a) + (c / b);
        cout << ans << '\n';
    }
    return 0;
}