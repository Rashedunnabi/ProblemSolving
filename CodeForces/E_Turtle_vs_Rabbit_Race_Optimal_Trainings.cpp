#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; ++i)
            cin >> a[i];

        vector<ll> preSum(n + 1, 0);
        for (ll i = 1; i <= n; ++i)
            preSum[i] = preSum[i - 1] + a[i - 1];

        // for (auto val : a)
        //     cout << val << ' ';
        // cout << endl;
        // for (auto val : preSum)
        //     cout << val << ' ';
        // cout << endl;

        ll q;
        cin >> q;

        while (q--)
        {
            ll l, u;
            cin >> l >> u;

            ll lo = l, hi = n, mid;
            ll k, extra, val, ans = n + 2, ansVal = INT_MIN;
            while (lo < hi)
            {
                mid = (lo + hi) / 2;

                k = preSum[mid] - preSum[l - 1];
                extra = u - k + 1;
                val = u * 1LL * (u + 1) / 2;
                if (extra < 0)
                    val -= (abs(extra) * 1ll * (abs(extra) + 1) / 2);
                if (extra > 0)
                    val -= (extra * 1LL * (extra - 1) / 2);

                if (ansVal == val)
                {
                    ans = min(ans, mid);
                    hi = mid - 1;
                }
                if (ansVal < val)
                {
                    ansVal = val;
                    ans = mid;
                    hi = mid - 1;
                }
                else
                {
                                }
            }

            for (ll i = l; i <= n; ++i)
            {
                k = preSum[i] - preSum[l - 1];
                extra = u - k + 1;
                val = u * 1LL * (u + 1) / 2;
                if (extra < 0)
                    val -= (abs(extra) * 1ll * (abs(extra) + 1) / 2);
                if (extra > 0)
                    val -= (extra * 1LL * (extra - 1) / 2);

                if (ansVal == val)
                {
                    ans = min(ans, i);
                }
                if (ansVal < val)
                {
                    ansVal = val;
                    ans = i;
                }
            }

            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}
