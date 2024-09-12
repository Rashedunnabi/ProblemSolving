#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(int vertex, int color, bool graph[101][101], vector<int> &vis)
    {
        int n = vis.size();
        for (int i = 0; i < n; i++)
        {
            if (i != vertex && graph[i][vertex])
            {
                if (vis[i] == color)
                    return false;
            }
        }
        return true;
    }

    bool func(int vertex, int color, bool graph[101][101], vector<int> &vis)
    {
        if (vertex < 0)
            return true;

        for (int i = 1; i <= color; i++)
        {
            if (check(vertex, i, graph, vis))
            {
                vis[vertex] = i;
                if (func(vertex - 1, color, graph, vis))
                    return true;
                vis[vertex] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int color, int n)
    {
        vector<int> vis(n);
        return func(n - 1, color, graph, vis);
    }
};
int main()
{
    // vertex,color,edge
    int n, m, e;
    cin >> n >> m >> e;
    bool gp[101][101];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        gp[x][y] = gp[y][x] = 1;
    }
    Solution ob;
    cout << ob.graphColoring(gp, m, n) << '\n';
    return 0;
}