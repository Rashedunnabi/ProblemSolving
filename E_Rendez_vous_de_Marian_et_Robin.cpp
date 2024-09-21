#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX

void dijkstra(int start, int n, vector<vector<pair<int, int>>> &graph, vector<int> &dist)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, h;
        cin >> n >> m >> h;

        vector<vector<pair<int, int>>> graph(n + 1);
        vector<int> horses(n + 1, 0);
        vector<int> horsePositions(h);

        for (int i = 0; i < h; i++)
        {
            cin >> horsePositions[i];
            horses[horsePositions[i]] = 1; // Mark vertices with horses
        }

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<int> distM(n + 1, INF);
        vector<int> distR(n + 1, INF);

        // Run Dijkstra for Marian from vertex 1
        dijkstra(1, n, graph, distM);

        // Run Dijkstra for Robin from vertex n
        dijkstra(n, n, graph, distR);

        // Calculate the earliest meeting time
        int earliestTime = INF;

        for (int i = 1; i <= n; i++)
        {
            if (distM[i] != INF && distR[i] != INF)
            {
                // Meeting without horse
                earliestTime = min(earliestTime, max(distM[i], distR[i]));

                // Meeting considering horse effect
                if (horses[i])
                {
                    for (auto &edge : graph[i])
                    {
                        int v = edge.first;
                        int w = edge.second / 2; // Halve the weight when using a horse
                        earliestTime = min(earliestTime, max(distM[i] + w, distR[i] + w));
                    }
                }
            }
        }

        cout << (earliestTime == INF ? -1 : earliestTime) << '\n';
    }

    return 0;
}
