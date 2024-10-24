#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;
        vector<int> v(n), vis(n);
        for (auto &i : v)
            cin >> i;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] != 0)
                continue;

            int j = i, cnt = 0;
            while (!vis[j])
            {
                cnt++;
                vis[j] = 10;
                j = v[j];
                j--;
            }
            int x = (cnt - 1) / 2;
            ans += x;
        }
        cout << ans << '\n';
    }

    return 0;
}