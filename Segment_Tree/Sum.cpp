#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 2, MOD = 1e9 + 7;

int tree[4 * N], a[N];

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = a[start];
        return;
    }

    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int left, int right)
{
    if (end < left || start > right)
    {
        return 0;
    }

    if (left <= start && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    int q1 = query(2 * node, start, mid, left, right);
    int q2 = query(2 * node + 1, mid + 1, end, left, right);

    return q1 + q2;
}

void update(int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        a[start] = val;
        tree[node] = val;
        return;
    }

    int mid = (start + end) / 2;
    if (idx <= mid)
    {
        update(2 * node, start, mid, idx, val);
    }
    else
    {
        update(2 * node + 1, mid + 1, end, idx, val);
    }

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(1, 0, n - 1);

    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int idx, val;
            cin >> idx >> val;
            update(1, 0, n - 1, idx, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            int ans = query(1, 0, n - 1, l, r);
            cout << ans << '\n';
        }
    }
    return 0;
}
