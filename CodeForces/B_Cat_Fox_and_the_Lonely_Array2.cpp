#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e5 + 2, MOD = 1e9 + 7;
ll tree[4 * N], a[N];
void build(ll node, ll st, ll en)
{
    if (st == en)
    {
        tree[node] = a[st];
        return;
    }

    ll mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    // operation
    tree[node] = tree[2 * node] | tree[2 * node + 1];
}

ll query(ll node, ll st, ll en, ll l, ll r)
{
    if (en < l || st > r)
    {
        return 0;
    }

    if (l <= st && en <= r)
        return tree[node];

    ll mid = (st + en) / 2;
    ll q1 = query(2 * node, st, mid, l, r);
    ll q2 = query(2 * node + 1, mid + 1, en, l, r);

    // operation
    return q1 | q2;
}

// before use segment tree build first
// build(1, 0, n - 1);
// update(1, 0, n - 1, idx, val); // a[idx]=val
// query(1, 0, n - 1, l, r);      // sum in range [l,r]

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, i;
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];

        build(1, 0, n - 1);

        auto possible = [&](ll mid) -> bool
        {
            ll value = tree[1];
            for (ll i = 0; i + mid <= n; i++)
            {
                ll val = query(1, 0, n - 1, i, i + mid - 1);
                if (val != value)
                    return false;
            }
            return true;
        };

        ll lo = 0, hi = n, mid;
        while (hi - lo > 1)
        {
            mid = lo + (hi - lo) / 2;
            possible(mid) ? hi = mid : lo = mid;
        }
        cout << hi << '\n';
    }
    return 0;
}