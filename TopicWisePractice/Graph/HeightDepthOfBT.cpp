#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> graph[N];
int height[N], depth[N];

void dfs(int vertex, int parent)
{
    for (int &child : graph[vertex])
    {
        if (child == parent)
            continue;

        // calculate depth of a node in  tree ?? uporer node 0
        depth[child] = depth[vertex] + 1;

        dfs(child, vertex);

        // calculate height of a node in tree ?? nicher node 0
        height[vertex] = max(height[vertex], height[child] + 1);
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

    cout << "Height of the tree \n";
    for (i = 1; i <= v; i++)
        cout << i << ' ';
    cout << '\n';
    for (i = 1; i <= v; i++)
        cout << height[i] << ' ';
    cout << '\n';
    cout << "\nDepth of the tree \n";
    for (i = 1; i <= v; i++)
        cout << i << ' ';
    cout << '\n';
    for (i = 1; i <= v; i++)
        cout << depth[i] << ' ';
    cout << '\n';

    return 0;
}