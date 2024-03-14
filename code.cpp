#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solution()
{
    ll n, m, k, d, i;
    cin >> n >> m >> k >> d;

    vector<ll> ans(n + 1);

    for (ll i = 0; i < n; i++)
    {
        vector<ll> v(m);
        for (ll &i : v)
            cin >> i;

        multiset<ll> mst;
        deque<ll> q;

        mst.insert(1);
        q.push_back(1);

        for (ll j = 1; j < m; j++)
        {
            ll cost = *mst.begin() + v[j] + 1LL;
            mst.insert(cost);
            q.push_back(cost);

            if (q.size() > d + 1)
            {
                auto it = mst.find(q.front());
                mst.erase(it);
                q.pop_front();
            }
        }
        ans[i + 1] = q.back();
    }

    for (i = 1; i <= n; i++)
        ans[i] += ans[i - 1];

    ll mini = LONG_LONG_MAX;

    for (i = 0; i <= n - k; i++)
    {
        mini = min(mini, ans[i + k] - ans[i]);
    }
    cout << mini << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
