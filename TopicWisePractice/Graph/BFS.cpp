#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;

vector<int> graph[N];
int level[N];

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

int main()
{
    int v, e, i;
    cin >> v >> e;

    for (i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bfs(1);

    for (i = 1; i <= v; i++)
    {
        cout << i << " " << level[i] << endl;
    }
}