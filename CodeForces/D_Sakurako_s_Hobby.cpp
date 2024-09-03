#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> p(n), ans(n), vis(n, -1);
        for (int &i : p)
            cin >> i, i--;

        string s;
        cin >> s;

        for (int i = 0; i < n; i++)
        {
            if (vis[i] != -1)
            {
                ans[i] = ans[vis[i]];
                continue;
            }

            int nxt = i, cnt = 0;
            while (vis[nxt] == -1)
            {
                cnt += (s[nxt] == '0');
                vis[nxt] = i;
                nxt = p[nxt];
            }
            ans[i] = cnt;
        }

        for (auto val : ans)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}