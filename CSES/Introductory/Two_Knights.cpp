#include <bits/stdc++.h>
using namespace std;
#define Rashed ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

int main()
{
    Rashed;
    ll n, ans = 0;
    cin >> n;

    for (ll i = 1; i <= n; i++)
    {
        ll x = (i * i) * ((i * i) - 1) / 2;
        ll y = 4 * (i - 2) * (i - 1);
        ans = x - y;
        cout << ans << "\n";
    }
    return 0;
}
