const int M = 1e9 + 7;
void dfs(int vertex, int par, vector<int> graph[], vector<int> &subtree_sum, vector<int> &val)
{
    subtree_sum[vertex] += val[vertex - 1];
    for (int child : graph[vertex])
    {
        if (child == par)
            continue;
        dfs(child, vertex, graph, subtree_sum, val);
        subtree_sum[vertex] += subtree_sum[child];
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int>> &B)
{
    vector<int> g[A.size() + 1];
    vector<int> subtree_sum(A.size() + 1, 0);

    for (auto edge : B)
    {
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
    }

    dfs(1, 0, g, subtree_sum, A);

    long long ans = 0;
    for (int i = 2; i <= A.size(); ++i)
    {
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1] - part1;
        ans = max(ans, (part1 * 1LL * part2) % M);
    }

    return ans;
}
