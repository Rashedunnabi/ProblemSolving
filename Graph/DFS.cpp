#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
vector<int> graph[N];
bool vis[N];

void dfs(int vertex)
{
    // Take action on vertex after entering the vertex
    vis[vertex] = true;
    for (auto child : graph[vertex])
    {
        if (vis[child])
            continue;
        // Take action on child before entering child node
        dfs(child);
        // Take action on child after exiting child node
    }
    // Take action on vertex before exiting the vertex
}

int main()
{
    int e, v, i;
    cin >> v >> e;

    for (i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    return 0;
}