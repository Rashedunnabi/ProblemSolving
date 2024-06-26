#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        vector<int> graph[n + 2];
        for (i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int source = min_element(v.begin(), v.end()) - v.begin();

        queue<int> q;
        vector<int> level(n + 2), ans;

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
                ans.push_back(child);
                level[child] = level[vertex] + 1;
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (auto val : ans)
            cout << val + 1 << ' ';
        cout << '\n';
    }
    return 0;
}