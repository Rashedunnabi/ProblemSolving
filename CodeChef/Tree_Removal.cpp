#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> graph(n);
        vector<int> values(n);
        for (int i = 0; i < n; ++i)
            cin >> values[i];

        for (int i = 0; i < n - 1; ++i)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int minNode = min_element(values.begin(), values.end()) - values.begin();

        vector<bool> visited(n, false);
        vector<int> order;
        queue<int> bfs;

        visited[minNode] = true;
        order.push_back(minNode);
        bfs.push(minNode);

        while (!bfs.empty())
        {
            int node = bfs.front();
            bfs.pop();
            for (int neighbor : graph[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    order.push_back(neighbor);
                    bfs.push(neighbor);
                }
            }
        }

        vector<int> answer(order.begin() + 1, order.end());
        reverse(answer.begin(), answer.end());

        cout << answer.size() << "\n";
        for (int i = 0; i < answer.size(); ++i)
        {
            cout << answer[i] + 1 << (i + 1 == answer.size() ? "\n" : " ");
        }
    }

    return 0;
}
