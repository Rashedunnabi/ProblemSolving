#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"

bool dfs(int vertex, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
{
    vis[vertex] = pathVis[vertex] = 1;
    for (auto child : adj[vertex])
    {
        if (pathVis[child])
            return true;
        if (!vis[child] && dfs(child, adj, vis, pathVis))
            return true;
    }
    pathVis[vertex] = 0;
    return false;
}
bool isCyclic(int n, vector<int> adj[])
{
    vector<int> vis(n), pathVis(n);
    bool isCycle = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
            isCycle |= dfs(i, adj, vis, pathVis);
    }
    return isCycle;
}

void solution()
{
    int n, k, i, j;
    cin >> n >> k;

    vector<int> adj[n];
    for (i = 0; i < k; i++)
    {
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        for (j = 1; j < n - 1; j++)
        {
            int x = v[j], y = v[j + 1];
            x--, y--;
            adj[x].push_back(y);
        }
    }
    if (isCyclic(n, adj))
        no;
    else
        yes;
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

/// with topological sort

/*#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"

bool isCyclic(int n, vector<int> adj[])
{
    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int v : adj[i])
        {
            inDegree[v]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    int visitedCount = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        visitedCount++;
        for (int v : adj[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
    return visitedCount != n;
}

void solution()
{
    int n, k, i, j;
    cin >> n >> k;

    vector<int> adj[n];
    for (i = 0; i < k; i++)
    {
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        for (j = 1; j < n - 1; j++)
        {
            int x = v[j], y = v[j + 1];
            x--, y--;
            adj[x].push_back(y);
        }
    }
    if (isCyclic(n, adj))
        no;
    else
        yes;
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
}*/