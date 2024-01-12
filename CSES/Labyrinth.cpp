#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
char ar[N][N];
char dir[N][N];
bool vis[N][N];

vector<char> path;
int n, m;
pair<int, int> st, en;

bool isValid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == false && ar[i][j] == '.';
}
vector<pair<int, int>> movements{
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}};
char position(int i)
{
    if (i == 0)
        return 'R';
    else if (i == 1)
        return 'L';
    else if (i == 2)
        return 'U';
    else
        return 'D';
}

bool bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});

    while (!q.empty())
    {
        auto val = q.front();
        q.pop();
        int x = val.first;
        int y = val.second;

        for (int i = 0; i < 4; i++)
        {
            int xx = x + movements[i].first;
            int yy = y + movements[i].second;

            // if (xx == en.first && yy == en.second)
            //     return true;

            if (isValid(xx, yy) && ar[xx][yy] == '.')
            {
                q.push({xx, yy});
                dir[xx][yy] = position(i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int i, j;
    cin >> n >> m;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cin >> ar[i][j];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (ar[i][j] == 'A')
                st.first = i, st.second = j;
            if (ar[i][j] == 'B')
                en.first = i, en.second = j;
        }
    }

    bool flag = bfs(st.first, st.second);

    return 0;
}