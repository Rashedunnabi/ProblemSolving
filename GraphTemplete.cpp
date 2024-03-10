#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int level[N], depth[N], height[N], vis[N], sumOfSubtree[N], primeCount[N], evenCount[N], oddCount[N], parent[N], Size[N], prime[N];
int dis[510][510];
vector<int> graph[N];

// Breadth-First Search (BFS)
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    level[source] = 1;
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        for (auto child : graph[vertex])
        {
            if (level[child])
                continue;
            q.push(child);
            level[child] = level[vertex] + 1;
        }
    }
}

// Depth-First Search (DFS)
void dfs1(int vertex)
{
    vis[vertex] = true;
    for (auto child : graph[vertex])
    {
        if (vis[child])
            continue;
        dfs1(child);
    }
}

// DFS on Tree
void dfs(int vertex, int parent)
{
    for (int &child : graph[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}

// Height and Depth of a Tree
void dfs(int vertex, int parent)
{
    for (int &child : graph[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

// Diameter of a Tree
void dfs(int vertex, int parent)
{
    for (int &child : graph[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}

// Lowest Common Ancestor
void dfs(int vertex, int par = -1)
{
    parent[vertex] = par;
    for (int &child : graph[vertex])
    {
        if (child == par)
            continue;
        dfs(child, vertex);
    }
}

vector<int> pathVec(int x)
{
    vector<int> v;
    while (x != -1)
    {
        v.push_back(x);
        x = parent[x];
    }
    return v;
}

// Pre-computation in Subtree, Sum of Subtree, Count even-odd, prime
void dfs(int vertex, int parent)
{
    sumOfSubtree[vertex] += vertex;
    primeCount[vertex] += (prime[vertex] == true);
    evenCount[vertex] += (vertex % 2 == 0);
    oddCount[vertex] += (vertex & 1);
    for (int &child : graph[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
        sumOfSubtree[vertex] += sumOfSubtree[child];
        primeCount[vertex] += primeCount[child];
        evenCount[vertex] += evenCount[child];
        oddCount[vertex] += oddCount[child];
    }
}

// Dijkstra's Algorithm
// int dijkstra(int source, int destination)
// {
//     vector<int> dis(N, INT_MAX);
//     multiset<pair<int, int>> st;
//     st.insert({0, source});
//     dis[source] = 0;
//     while (!st.empty())
//     {
//         auto it = *st.begin();
//         st.erase(st.begin());
//         int vertex = it.second, weight = it.first;
//         if (vis[vertex])
//             continue;
//         vis[vertex] = 1;
//         for (auto child : graph[vertex])
//         {
//             int node = child.first, dist = child.second;
//             if (dis[node] > dis[vertex] + dist)
//             {
//                 dis[node] = dis[vertex] + dist;
//                 st.insert({dis[node], node});
//             }
//         }
//     }
//     return dis[destination];
// }

// Floyd Warshall Algorithm
void floydWarshall()
{
    int n = 300, INF = INT_MAX;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] != INF && dis[k][j] != INF)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

// Disjoint Set Union
void make(int v)
{
    parent[v] = v, Size[v] = 1;
}
int Find(int v)
{
    return v == parent[v] ? v : parent[v] = Find(parent[v]);
}

void Union(int a, int b)
{
    a = Find(a), b = Find(b);
    if (a != b)
    {
        if (Size[a] < Size[b])
            swap(a, b);
        parent[b] = a, Size[a] += Size[b];
    }
}

// Kruskal's Algorithm
int kruskal()
{
    int total_cost = 0;
    vector<pair<int, pair<int, int>>> edges;
    for (auto &edge : edges)
    {
        int wt = edge.first, u = edge.second.first, v = edge.second.second;
        if (Find(u) != Find(v))
        {
            Union(u, v);
            total_cost += wt;
        }
    }
    return total_cost;
}

// Cycle Detection in Directed Graph
bool dfs(int vertex, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
{
    vis[vertex] = 1, pathVis[vertex] = 1;
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
    for (int i = 0; i < n; i++)
        if (!vis[i] && dfs(i, adj, vis, pathVis))
            return true;
    return false;
}

// Using Topological Sorting
bool isCyclic(int n, vector<int> adj[])
{
    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; ++i)
        for (int v : adj[i])
            inDegree[v]++;
    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (inDegree[i] == 0)
            q.push(i);
    int visitedCount = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        visitedCount++;
        for (int v : adj[u])
        {
            if (--inDegree[v] == 0)
                q.push(v);
        }
    }
    return visitedCount != n;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    return 0;
}