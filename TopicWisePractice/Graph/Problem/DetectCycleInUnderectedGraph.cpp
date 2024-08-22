#include <bits/stdc++.h>
using namespace std;

bool dfs(int vertex, int parent, vector<int> graph[], bool vis[])
{
    vis[vertex] = true;
    bool isLoopExist = false;
    for (int child : graph[vertex])
    {
        if (child == parent)
            continue;
        if (vis[child])
            return true;
        isLoopExist |= dfs(child, vertex, graph, vis);
    }
    return isLoopExist;
}

bool isCycle(int v, vector<int> graph[])
{
    bool vis[v] = {0};
    bool isLoopExist = false;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            isLoopExist |= dfs(i, -1, graph, vis);
        }
    }
    return isLoopExist;
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<int> graph[v];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cout << isCycle(v, graph) << '\n';

    return 0;
}