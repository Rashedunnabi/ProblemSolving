#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
const int N = 2e5 + 7;
int i, n;
string s[2];
int vis[2][N];

inline pii go_to(int x, int y)
{
    return (s[x][y] == '>') ? pii(x, y + 1) : pii(x, y - 1);
}
void dfs(pii it)
{
    int x = it.first, y = it.second;
    if (vis[x][y])
        return;
    vis[x][y] = 1;
    if (y)
        dfs(go_to(x, y - 1));
    if (y < n - 1)
        dfs(go_to(x, y + 1));
    dfs(go_to(!x, y));
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n >> s[0] >> s[1];
        dfs({0, 0});
        cout << (vis[1][n - 1] ? "YES\n" : "NO\n");
        for (i = 0; i < n; i++)
            vis[0][i] = vis[1][i] = 0;
    }
    return 0;
}