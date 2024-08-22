#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 2;
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

    tree[node] = tree[2 * node] + tree[2 * node + 1];
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

    // operation
    return q1 + q2;
}

void update(int node, int st, int en, int idx, int val)
{
    if (st == en)
    {
        a[st] = val;
        tree[node] = val;
        return;
    }

    int mid = (st + en) / 2;
    if (idx <= mid)
    {
        update(2 * node, st, mid, idx, val);
    }
    else
    {
        update(2 * node + 1, mid + 1, en, idx, val);
    }
    // operation
    tree[node] = (tree[2 * node] >= 0 ? tree[2 * node] : 0) + (tree[2 * node + 1] >= 0 ? tree[2 * node + 1] : 0);
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n - 1);
    cout << tree[1] << '\n';

    for (int i = 0; i <= 4 * n; i++)
        cout << tree[i] << ' ';
    cout << '\n';

    while (q--)
    {
        int ind, val;
        cin >> ind >> val;
    }

    return 0;
}