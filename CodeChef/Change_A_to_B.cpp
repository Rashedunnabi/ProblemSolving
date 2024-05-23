#include <bits/stdc++.h>
using namespace std;
#define ll long long

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll a, b, x, i, ans = 0;
        cin >> a >> b >> x;

        while (1)
        {
            if (b % x == 0 && b / x >= a)
            {
                ans++;
                b = b / x;
            }
            else if (b % x == 0)
            {
                ans += b - a;
                break;
            }
            else
            {
                ans += (b % x);
                b -= (b % x);
            }
            // cout << a << ' ' << b << ' ' << ans << '\n';
        }
        cout << ans << '\n';
    }
    return 0;
}