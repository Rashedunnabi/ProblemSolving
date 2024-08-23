#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll n, target;
    cin >> n >> target;
    vector<ll> v(n);
    for (ll &i : v)
        cin >> i;

    ll i = 0, j = 0, sum = 0, ans = 0;
    for (i = 0; i < n; i++)
    {
        sum += v[i];
        while (sum > target)
            sum -= v[j++];
        if (sum <= target)
        {
            ll x = i - j + 1;
            ans += (x * (x + 1) / 2);
        }
    }
    cout << ans << '\n';

    return 0;
}