#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int N = 2e5 + 7;
int parent[N], Size[N];
void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
}
int Find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = Find(parent[v]);
}
void Union(int a, int b)
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

bool dfs(int vertex, int pat, int target, vector<int> &path, vector<int> graph[])
{
    path.push_back(vertex);
    if (vertex == target)
        return true;

    for (int child : graph[vertex])
    {
        if (child == pat)
            continue;
        bool flag = dfs(child, vertex, target, path, graph);
        if (flag)
            return true;
    }
    path.pop_back();
    return false;
}

void solution()
{
    int n, e, i, u, v, w;
    cin >> n >> e;

    vector<int> graph[n + 1];
    vector<pair<int, pair<int, int>>> vp;

    for (i = 0; i <= n; i++)
        make(i);

    for (i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        vp.push_back({w, {u, v}});
    }
    sort(rall(vp));

    int tu, tv, tw;
    for (auto val : vp)
    {
        w = val.first, u = val.second.first, v = val.second.second;

        if (Find(u) == Find(v))
            tu = u, tv = v, tw = w;
        else
        {
            Union(u, v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     if (graph[i].size() == 0)
    //         continue;
    //     cout << i << ": ";
    //     for (auto e : graph[i])
    //         cout << e << ' ';
    //     cout << '\n';
    // }

    vector<int> path;
    auto it = dfs(tu, -1, tv, path, graph);

    // cout << tu << ' ' << tv << endl;
    cout << tw << ' ' << path.size() << '\n';
    for (int &e : path)
        cout << e << ' ';
    cout << '\n';
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define INF 2047483647
#define INFL 9223372036854775807
#define ll long long
#define int long long
#define pii pair<ll, ll>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ull unsigned long long
// #define M 1000000007
#define M 998244353
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define take(x) scanf("%d", &x)
#define DE(x) printf("\ndebug %d\n", x);
#define vout(x)                        \
    for (int i = 0; i < x.size(); i++) \
        printf("%d ", x[i]);
#define pie acos(-1)
#define MOD 998244353
#define endl '\n'

#define eps 0.0000001

const int N = 200005;
vector<int> adj[N];
int parent[N];
int rnk[N];
void Dsu(int n)
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        rnk[i] = 0;
    }
}
int Find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = Find(parent[v]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b)
    {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            rnk[a]++;
    }
}

struct Edge
{
    int u, v, w;
};

bool cmp(Edge a, Edge b)
{
    return a.w > b.w;
}

int target;
vector<int> path;
bool dfs(int u, int p)
{

    path.push_back(u);
    if (u == target)
        return true;

    for (auto v : adj[u])
    {
        if (v == p)
            continue;
        bool ret = dfs(v, u);
        if (ret)
            return true;
    }
    path.pop_back();
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    Dsu(n);
    path.clear();
    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
    }
    Edge edges[m];
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    sort(edges, edges + m, cmp);
    int ind = 0;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        if (Find(u) != Find(v))
        {
            Union(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            continue;
        }
        else
        {
            ind = i;
        }
    }
    target = edges[ind].v;
    dfs(edges[ind].u, 0);

    cout << edges[ind].w << " " << path.size() << endl;
    for (auto p : path)
        cout << p << " ";
    cout << endl;
}

signed main()
{
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}

/* jasprit sing

#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define endl '\n'

vector<int> f(200001), h(200001);
int find(int i)
{
    if (f[i] != i)
    {
        f[i] = find(f[i]);
    }
    return f[i];
}
void uion(int u, int v)
{
    int a = find(u);
    int b = find(v);
    if (a != b)
    {
        if (h[a] > h[b])
        {
            f[b] = a;
            h[a] = max(h[a], h[b] + 1);
        }
        else
        {
            f[a] = b;
            h[b] = max(h[b], h[a] + 1);
        }
    }
}
void dfs(int i, vector<int> &b, vector<int> v[], int &a2, int &a1, vector<int> &v1, vector<int> &v2)
{
    b[i] = 1;
    v1.push_back(i);
    if (i == a2)
        v2 = v1;
    for (auto u : v[i])
    {
        if (!b[u])
        {
            if (i == a1 && u == a2)
                continue;
            dfs(u, b, v, a2, a1, v1, v2);
        }
    }
    v1.pop_back();
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v[n + 1];
        vector<pair<int, pair<int, int>>> e;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            v[a].push_back(b);
            v[b].push_back(a);
            e.push_back({c, {a, b}});
        }
        sort(e.rbegin(), e.rend());
        for (int i = 1; i <= n; i++)
        {
            f[i] = i;
            h[i] = 0;
        }
        int a1, a2;
        int f;
        for (auto u : e)
        {
            if (find(u.second.first) == find(u.second.second))
                a1 = u.second.first, a2 = u.second.second, f = u.first;
            uion(u.second.first, u.second.second);
        }
        vector<int> b(n + 1), v1, v2;
        dfs(a1, b, v, a2, a1, v1, v2);
        cout << f << " " << v2.size() << endl;
        for (auto u : v2)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
*/
* /