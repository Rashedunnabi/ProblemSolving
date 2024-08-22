#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k, i;
        cin >> n >> k;

        vector<ll> v(n);
        for (ll &i : v)
        {
            cin >> i;
            i %= k;
        }

        sort(v.begin(), v.end());
        ll maxi = v[n - 1], ans = v[n - 1] - v[0];
        for (i = 0; i < n - 1; i++)
        {
            ans = min(ans, v[i] + k - v[i + 1]);
        }
        cout << ans << '\n';
    }
    return 0;
}