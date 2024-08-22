#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

int distance(int x, int y, int xx, int yy)
{
    int dis = 1LL * (x - xx) * (x - xx) + 1LL * (y - yy) * (y - yy);
    return dis;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;

        vector<pii> vp(n);
        for (i = 0; i < n; i++)
            cin >> vp[i].first >> vp[i].second;

        int xs, ys, xt, yt;
        cin >> xs >> ys >> xt >> yt;

        bool flag = true;
        for (auto p : vp)
        {
            if (distance(xs, ys, xt, yt) >= distance(p.first, p.second, xt, yt))
            {
                flag = false;
                break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}