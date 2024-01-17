#include <bits/stdc++.h>
using namespace std;

int graph[8][8], level[8][8];

void reset()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            graph[i][j] = 0;
            level[i][j] = 0;
        }
    }
}

bool isValid(int x, int y)
{
    return x < 8 && y < 8 && x >= 0 && y >= 0;
}

vector<pair<int, int>> movements = {
    {-1, 2}, {-1, -2}, {1, 2}, {1, -2}, {2, -1}, {2, 1}, {-2, -1}, {-2, 1}};

int bfs(string s1, string s2)
{
    int x1 = s1[0] - 'a';
    int y1 = s1[1] - '1';
    int x2 = s2[0] - 'a';
    int y2 = s2[1] - '1';

    queue<pair<int, int>> q;

    q.push({x1, y1});

    graph[x1][y1] = 1;

    while (!q.empty())
    {
        pair<int, int> p;
        p = q.front();
        q.pop();

        int x = p.first, y = p.second;

        for (auto movement : movements)
        {
            int a, b;
            a = x + movement.first;
            b = y + movement.second;

            if (!isValid(a, b))
                continue;
            if (graph[a][b])
                continue;

            q.push({a, b});
            graph[a][b] = 1;
            level[a][b] = level[x][y] + 1;
        }
    }
    return level[x2][y2];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        reset();
        string s1, s2;
        cin >> s1 >> s2;

        cout << bfs(s1, s2) << endl;
    }

    return 0;
}