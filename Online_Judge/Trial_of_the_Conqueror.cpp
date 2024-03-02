#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300003;
vector<int> adj[MAXN];
vector<int> h(MAXN, INT_MAX);
vector<int> cnt(MAXN);
vector<int> ans(MAXN);
int k;

void dfs(int v, int p)
{
    int x = 0;
    vector<int> ind;
    for (int u : adj[v])
    {
        if (u == p)
            continue;
        x++;
        dfs(u, v);
        h[v] = min(h[v], h[u] + 1);
        if (h[u] < k)
        {
            cnt[v] += cnt[u];
            ind.push_back(u);
        }
        else
        {
            ans[v] = max(ans[v], ans[u]);
        }
    }
    ans[v] += cnt[v];
    for (int u : ind)
    {
        ans[v] = max(ans[v], ans[u] + cnt[v] - cnt[u]);
    }
    if (!x)
    {
        h[v] = 0;
        cnt[v] = 1;
        ans[v] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        {
            adj[i].clear();
            cnt[i] = 0;
            ans[i] = 0;
            h[i] = INT_MAX;
        }
        for (int i = 1; i < n; ++i)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1, 0);
        int out = 0;
        for (int i = 1; i <= n; ++i)
        {
            out = max(out, ans[i]);
        }
        cout << out << endl;
    }

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Node {
    int height = INT_MAX;
    int count = 0;
    int answer = 0;
};

void dfs(int v, int p, const vector<vector<int>>& adj, vector<Node>& nodes, int k) {
    int x = 0;
    vector<int> ind;
    for (int u : adj[v]) {
        if (u == p) continue;
        x++;
        dfs(u, v, adj, nodes, k);
        nodes[v].height = min(nodes[v].height, nodes[u].height + 1);
        if (nodes[u].height < k) {
            nodes[v].count += nodes[u].count;
            ind.push_back(u);
        } else {
            nodes[v].answer = max(nodes[v].answer, nodes[u].answer);
        }
    }
    nodes[v].answer += nodes[v].count;
    for (int u : ind) {
        nodes[v].answer = max(nodes[v].answer, nodes[u].answer + nodes[v].count - nodes[u].count);
    }
    if (!x) {
        nodes[v].height = 0;
        nodes[v].count = 1;
        nodes[v].answer = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> adj(n + 1);
        vector<Node> nodes(n + 1);

        for (int i = 1; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }

        dfs(1, 0, adj, nodes, k);

        int out = 0;
        for (int i = 1; i <= n; ++i) {
            out = max(out, nodes[i].answer);
        }
        cout << out << '\n';
    }

    return 0;
}
*/