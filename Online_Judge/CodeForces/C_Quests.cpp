#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

void solution()
{
    ll n, k, i;
    cin >> n >> k;

    ll a[n], b[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];

    ll ans = 0, maxi = 0, pre = 0;
    for (i = 0; i < min(n, k); i++)
    {
        pre += a[i];
        maxi = max(maxi, b[i]);
        ll value = pre + (k - i - 1) * maxi;
        ans = max(ans, value);
    }
    cout << ans << '\n';
}

int main()
{
    Faster;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}