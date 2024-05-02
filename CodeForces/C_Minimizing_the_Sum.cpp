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
        ll n, i, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (ll &i : v)
            cin >> i;

        if (n == 1 || k == 0)
        {
            ll sum = accumulate(v.begin(), v.end(), 0LL);
            cout << sum << '\n';
            continue;
        }

        while (k--)
        {
            ll ind = -1, maxi = LONG_LONG_MIN, value = INT_MAX;
            for (i = 0; i < n - 1; i++)
            {
                ll dif = abs(v[i] - v[i + 1]);
                if (dif == maxi)
                {
                    if (min(v[i], v[i + 1]) <= value)
                    {
                        ind = i;
                        value = min(v[i], v[i + 1]);
                    }
                }
                if (dif > maxi)
                {
                    ind = i;
                    maxi = dif;
                    value = min(v[i], v[i + 1]);
                }
            }
            if (ind != -1)
            {
                ll val = min(v[ind], v[ind + 1]);
                val = min(val, value);
                v[ind] = v[ind + 1] = val;
            }
        }

        ll sum = accumulate(v.begin(), v.end(), 0LL);
        cout << sum << '\n';
    }
    return 0;
}