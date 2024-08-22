#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7, inf = INT_MAX;
vector<pair<int, int>> graph[N];

int dijkstra(int source, int destination)
{
    vector<bool> vis(N, 0);
    vector<int> dis(N, inf);
    multiset<pair<int, int>> st; // weight,node
    st.insert({0, source});
    dis[source] = 0;

    while (st.size() > 0)
    {
        auto it = *st.begin();
        st.erase(st.begin());

        int vertex = it.second, weight = it.first;
        if (vis[vertex])
            continue;
        vis[vertex] = 1;

        for (auto child : graph[vertex])
        {
            int node = child.first;
            int dist = child.second;

            if (dis[node] > dis[vertex] + dist)
            {
                dis[node] = dis[vertex] + dist;
                st.insert({dis[node], node});
            }
        }
    }
    return dis[destination];
}

int main()
{
    int v, e, s, d, i;
    cin >> v >> e >> s >> d; // node,edge,source,destination

    for (i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w}); // node--->(connected node,weight)
        graph[y].push_back({x, w}); // node---->(connected node,weight)
    }
    cout << dijkstra(s, d) << '\n';

    return 0;
}

/*

4 5 1 4
1 2 1
1 3 5
1 4 5
2 4 7
3 4 1

ans 5

*/
