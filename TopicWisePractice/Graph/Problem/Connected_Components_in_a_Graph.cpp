// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/?purpose=login&source=problem-page&update=google

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> graph[N];
bool vis[N];

void dfs(int vertex)
{
    vis[vertex] = true;
    for (auto child : graph[vertex])
    {
        if (vis[child])
            continue;
        dfs(child);
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int e, v, i;
    cin >> v >> e;

    for (i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int ans = 0;
    for (i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            ans++;
            dfs(i);
        }
    }
    cout << ans << '\n';
    return 0;
}