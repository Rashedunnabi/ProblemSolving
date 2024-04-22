// LCA---Lowest Common Ancestor

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> graph[N];
int parent[N];

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

    // assume 1 is the root node
    dfs(1);

    int x, y;
    cin >> x >> y;
    vector<int> path1 = pathVec(x);
    vector<int> path2 = pathVec(y);

    reverse(path1.begin(), path1.end());
    reverse(path2.begin(), path2.end());

    int node = 0, n = min(path1.size(), path2.size());
    for (i = 0; i < n; i++)
    {
        if (path1[i] == path2[i])
            node = path1[i];
        else
            break;
    }
    cout << "Lowest Common Ancestor: " << node << '\n';

    return 0;
}