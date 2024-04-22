#include <bits/stdc++.h>
using namespace std;
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int mat[8][8], vis[8][8];

bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        memset(mat, 0, sizeof(mat));

        string s1, s2;
        cin >> s1 >> s2;

        int sr, sc, fr, fc, ans = 0;
        sr = s1[0] - 'a', sc = s1[1] - '1';
        fr = s2[0] - 'a', fc = s2[1] - '1';

        vector<pair<int, int>> movements = {
            {1, 2},
            {1, -2},
            {2, 1},
            {2, -1},
            {-1, 2},
            {-1, -2},
            {-2, 1},
            {-2, -1},
        };

        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = 1;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first, y = it.second;

            for (auto movement : movements)
            {
                int xx = x + movement.first;
                int yy = y + movement.second;

                if (isValid(xx, yy) && !vis[xx][yy])
                {
                    q.push({xx, yy});
                    vis[xx][yy] = 1;
                    mat[xx][yy] = mat[x][y] + 1;
                }
            }
        }
        cout << mat[fr][fc] << '\n';
    }
    return 0;
}