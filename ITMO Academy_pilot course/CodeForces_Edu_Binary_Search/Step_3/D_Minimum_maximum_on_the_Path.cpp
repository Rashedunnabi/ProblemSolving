#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, m, d, lo, hi, mid;
const ll N = 1e5 + 10;
vector<pair<ll, ll>> graph[N];
int parent[N];
bool vis[N];

bool check(ll mid)
{
    for (int i = 0; i <= n + 1; i++)
        vis[i] = parent[i] = 0;

    queue<pair<ll, ll>> q; // node,d
    q.push({1, d});
    vis[1] = true;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        ll node = it.first, newD = it.second;
        if (newD <= 0)
            continue;
        if (node == n)
            return true;

        vis[node] = 1;
        for (auto child : graph[node])
        {
            if (vis[child.first] || child.second > mid)
                continue;
            q.push({child.first, newD - 1});
            parent[child.first] = node;
            vis[child.first] = 1;
        }
    }
    return vis[n];
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> d;

    lo = INT_MAX, hi = -1;
    for (int i = 0; i < m; i++)
    {
        ll x, y, c;
        cin >> x >> y >> c;
        lo = min(lo, c), hi = max(hi, c); // finding low and high value for binary search
        graph[x].push_back({y, c});       // x-y connected with c weight
    }

    hi++, lo--;

    bool flag = true;
    while (hi - lo > 1)
    {
        mid = lo + (hi - lo) / 2;

        if (check(mid))
        {
            hi = mid;
            flag = false;
        }
        else
            lo = mid;
    }

    if (flag)
    {
        cout << -1 << '\n';
    }
    else
    {
        vector<ll> ans;

        auto it = check(hi);
        ans.push_back(n);
        while (parent[n] != 0)
        {
            ans.push_back(parent[n]);
            n = parent[n];
        }

        reverse(ans.begin(), ans.end());
        cout << ans.size() - 1 << '\n';
        for (auto val : ans)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}
