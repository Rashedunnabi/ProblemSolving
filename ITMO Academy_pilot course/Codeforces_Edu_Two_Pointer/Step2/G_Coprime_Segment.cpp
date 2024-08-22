#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
const int N = 1e5 + 2, MOD = 1e9 + 7;

int tree[4 * N], a[N];

void build(int node, int st, int en)
{
    if (st == en)
    {
        tree[node] = a[st];
        return;
    }

    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);

    tree[node] = __gcd(tree[2 * node], tree[2 * node + 1]);
}
int query(int node, int st, int en, int l, int r)
{
    if (en < l || st > r)
    {
        return 0;
    }

    if (l <= st && en <= r)
        return tree[node];

    int mid = (st + en) / 2;
    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, en, l, r);

    return __gcd(q1, q2);
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);
    if (tree[1] != 1)
    {
        cout << -1 << '\n';
        return 0;
    }

    auto possible = [&](int mid) -> bool
    {
        for (int i = 0; i + mid <= n; i++)
        {
            if (query(1, 0, n - 1, i, i + mid - 1) == 1)
                return true;
        }
        return false;
    };

    int lo = 0, hi = n, mid;
    while (hi - lo > 1)
    {
        mid = lo + (hi - lo) / 2;
        possible(mid) ? hi = mid : lo = mid;
    }
    cout << hi << '\n';
    return 0;
}
