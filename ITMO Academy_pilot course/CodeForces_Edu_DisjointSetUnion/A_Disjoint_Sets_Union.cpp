#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
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
    return parent[v] = Find(parent[v]); // path compression
}

void Union(int a, int b)
{
    a = Find(a), b = Find(b);
    if (a == b)
        return;
    // Union by size
    if (Size[a] < Size[b])
        swap(a, b);
    parent[b] = a;
    Size[a] += Size[b];
}
//  Before using DSU make sure you call the make function
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n, m, i;
    cin >> n >> m;

    for (i = 0; i <= n; i++)
        make(i);

    for (i = 0; i < m; i++)
    {
        string s;
        int u, v;
        cin >> s >> u >> v;
        if (s == "union")
            Union(u, v);
        else
            cout << (Find(u) == Find(v) ? "YES\n" : "NO\n");
    }

    return 0;
}