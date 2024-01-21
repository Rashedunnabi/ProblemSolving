#include <bits/stdc++.h>
using namespace std;
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

const ll N = 1e5 + 7;
ll parent[N], Size[N];
void make(ll v)
{
    parent[v] = v;
    Size[v] = 1;
}

ll Find(ll v)
{
    if (v == parent[v])
        return v;
    return parent[v] = Find(parent[v]);
}

void Union(ll a, ll b)
{
    a = Find(a);
    b = Find(b);
    if (a == b)
        return;

    // Union by size
    if (Size[a] < Size[b])
        swap(a, b);
    parent[b] = a;
    Size[a] += Size[b];
}

int main()
{
    Faster;

    ll n, i;
    cin >> n;

    vector<pair<ll, ll>> vp;
    for (i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        vp.push_back({x, y});
    }

    vector<ll> c(n), k(n);
    for (ll &i : c)
        cin >> i;
    for (ll &i : k)
        cin >> i;

    vector<pair<ll, pair<ll, ll>>> edges;

    for (i = 0; i < n; i++)
    {
        for (ll j = i + 1; j < n; j++)
        {
            ll cost = (k[i] + k[j]) * (abs(vp[i].first - vp[j].first) + abs(vp[i].second - vp[j].second));
            edges.push_back({cost, {i + 1, j + 1}});
        }
    }

    for (i = 0; i < n; i++)
    {
        edges.push_back({c[i], {0, i + 1}});
    }
    sort(edges.begin(), edges.end());

    for (i = 1; i <= n; i++)
        make(i);

    vector<ll> power;
    vector<pair<ll, ll>> conection;

    ll total_cost = 0;
    for (auto &edge : edges)
    {
        ll wt = edge.first;
        ll u = edge.second.first;
        ll v = edge.second.second;

        if (Find(u) == Find(v))
            continue;
        Union(u, v);
        total_cost += wt;
        if (u > 0 && v > 0)
            conection.push_back({u, v});
        else
            power.push_back(max(u, v));
    }
    sort(power.begin(), power.end());
    sort(conection.begin(), conection.end());

    cout << total_cost << '\n';
    cout << power.size() << '\n';
    for (auto i : power)
        cout << i << ' ';
    cout << '\n';

    cout << conection.size() << '\n';
    for (auto val : conection)
        cout << val.first << ' ' << val.second << '\n';

    return 0;
}