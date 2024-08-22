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

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(v.begin(), v.end(), v[i] + target + 1);
        ans += n - (it - v.begin());
    }
    cout << ans << '\n';

    return 0;
}