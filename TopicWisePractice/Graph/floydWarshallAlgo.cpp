#include <bits/stdc++.h>
using namespace std;
const int N = 510, INF = INT_MAX;

int dis[N][N];

void reset()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dis[i][j] = (i == j) ? 0 : INF;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    reset();

    int n, m, i, j, k;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        dis[x][y] = wt;
    }

    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (dis[i][k] != INF && dis[k][j] != INF)
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dis[i][j] == INF)
                cout << "I ";
            else
                cout << dis[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}