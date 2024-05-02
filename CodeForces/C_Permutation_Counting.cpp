#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll k, n, i;
        cin >> n >> k;
        vector<ll> v(n);
        for (ll &i : v)
            cin >> i;

        if (n == 1)
        {
            cout << k + v[0] << endl;
            continue;
        }
        sort(v.begin(), v.end());
        ll prev = v[0], rem = 0;
        bool flag = 0;
        for (ll i = 1; i < n; i++)
        {
            ll cur = v[i], diff = cur - prev, tot = diff * i;
            if (tot <= k)
            {
                k -= tot;
                prev = cur;
                if (i == n - 1 and k > 0)
                    flag = 1;
            }
            else
            {
                prev += (k / i);
                rem += (k % i) + (n - i);
                break;
            }
        }
        if (flag)
        {
            prev += (k / n);
            rem += (k % n);
        }
        prev -= 1;
        ll ans = (prev * n) + 1 + rem;
        cout << ans << '\n';
    }
    return 0;
}