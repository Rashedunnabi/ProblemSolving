#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
vector<int> graph[N];
vector<int> g[N];

bool vis[N];

void dfs(int vertex)
{
    if (vertex)
        return;
    vis[vertex] = true;

    for (auto child : graph[vertex])
    {
        dfs(child);
    }
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