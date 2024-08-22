#include <bits/stdc++.h>
using namespace std;
#define Rashed ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
const int mod = 1e9 + 7;

ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = power(a, b / 2);
    if (b & 1)
        return ((res % mod) * (res % mod) * a % mod) % mod;
    else
        return ((res % mod) * (res % mod)) % mod;
}
int main()
{
    Rashed;
    ll n;
    cin >> n;
    ll ans = power(2, n);
    cout << ans << "\n";
    return 0;
}