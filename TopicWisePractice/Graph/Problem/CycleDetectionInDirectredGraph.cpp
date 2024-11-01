#include <bits/stdc++.h>
using namespace std;

bool dfs(int vertex, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
{
    vis[vertex] = 1;
    pathVis[vertex] = 1;
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
int main()
{
    int v, e, i;
    cin >> v >> e;

    vector<int> adj[v];
    for (i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    cout << isCyclic(v, adj) << '\n';
    return 0;
}

// using topological sorting

/*

bool isCyclic(int n, vector<int> adj[]) {
    vector<int> inDegree(n, 0);
    // Calculate in-degrees for each vertex
    for (int i = 0; i < n; ++i) {
        for (int v : adj[i]) {
            inDegree[v]++;
        }
    }
    queue<int> q;
    // Add all vertices with in-degree 0 to the queue
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    int visitedCount = 0;
    // Process vertices in topological order
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visitedCount++;
        // Reduce in-degree of adjacent vertices
        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    // If the number of visited vertices is not equal to the total number of vertices, there is a cycle
    return visitedCount != n;
}

*/