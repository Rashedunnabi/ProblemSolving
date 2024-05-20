#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll n, target, i;
    cin >> n >> target;
    vector<ll> v(n + n), preSum(n + n + 1);
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
        v[i + n] = v[i];
    }

    for (i = 0; i < n + n; i++)
        preSum[i + 1] = preSum[i] + v[i];

    ll sum = accumulate(v.begin(), v.begin() + n, 0LL);
    ll div = (target / sum);
    ll rem = target % sum;
    ll length = INT_MAX, ind = -1;
    for (i = 0; i <= n; i++)
    {
        auto it = lower_bound(preSum.begin(), preSum.end(), preSum[i] + rem);
        ll len = (it - preSum.begin()) - i;
        if (length > len)
        {
            length = len;
            ind = i + 1;
        }
        // cout << length << ' ' << i + 1 << ' ' << (it - preSum.begin()) << ' ' << *it - preSum[i] << '\n';
    }
    length += (div * 1ll * n);
    cout << ind << ' ' << length << '\n';

    return 0;
}