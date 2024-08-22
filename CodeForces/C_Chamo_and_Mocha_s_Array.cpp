#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll &x : v)
            cin >> x;

        if (n <= 2)
        {
            ll ans = min(v[0], v[1]);
            cout << ans << '\n';
            continue;
        }
        ll ans = 0;
        for (ll i = 0; i < n - 2; i++)
        {
            vector<ll> arr = {v[i], v[i + 1], v[i + 2]};
            sort(arr.begin(), arr.end());
            ans = max(ans, arr[1]);
        }
        for (ll i = 1; i < n; i++)
            ans = max(ans, min(v[i], v[i - 1]));

        sort(v.begin(), v.end());
        ll newAns = v[(n - 1) / 2];
        ans = max(ans, newAns);
        cout << ans << '\n';
    }

    return 0;
}
