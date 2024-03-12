#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

const int N = 101, M = 2e5 + 7;
ll ans[N], v[M], value[M];
multiset<ll> mst;

void solution()
{
    ll n, m, k, d, i;
    cin >> n >> m >> k >> d;

    for (i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> v[j];

        mst.clear();
        mst.insert(1);
        for (ll j = 1; j < m; j++)
        {
            ll val = *mst.begin() + v[j] + 1;
            mst.insert(val);
            value[j] = val;

            if (j - d >= 1)
                mst.erase(mst.find(value[j - d - 1]));
        }
        ans[i + 1] = value[m - 1];
    }

    for (i = 1; i <= n; i++)
        ans[i] += ans[i - 1];

    ll miniAns = LONG_LONG_MAX;

    for (i = 0; i + k <= n; i++)
    {
        ll val = ans[i + k] - ans[i];
        miniAns = min(miniAns, val);
    }
    cout << miniAns << '\n';
}

int main()
{
    Faster;
    ll t = 1;
    value[0] = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}