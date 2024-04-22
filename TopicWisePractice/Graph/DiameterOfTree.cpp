// Diameter is the the maximum lenght of two node

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> graph[N];
int depth[N];

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
    dfs(1, 0);

    int node, maxi = 0;
    for (i = 1; i <= v; i++)
    {
        if (depth[i] > maxi)
        {
            maxi = depth[i];
            node = i;
        }
        depth[i] = 0;
    }

    dfs(node, -1);

    for (i = 1; i <= v; i++)
    {
        maxi = max(maxi, depth[i]);
    }
    cout << maxi << '\n';

    return 0;
}