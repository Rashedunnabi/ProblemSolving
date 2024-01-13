#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> graph[N];

// dfs for tree

void dfs(int vertex, int parent)
{
    for (int &child : graph[vertex])
    {
        if (child == parent)
            continue;
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

    return 0;
}