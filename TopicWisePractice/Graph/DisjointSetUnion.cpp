#include <bits/stdc++.h>
using namespace std;
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

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
    int n, k;
    cin >> n >> k;

    // call make function
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }

    while (k--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    // find  connected components using DSU

    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        if (Find(i) == i)
            cc++;
    }
    cout << cc << '\n';

    return 0;
}