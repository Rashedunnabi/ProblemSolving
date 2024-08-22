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
        int n, m, k, w;
        cin >> n >> m >> k >> w;

        vector<int> v(w), val;
        for (int &i : v)
            cin >> i;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int lbx = max(0LL, i - k + 1), upx = min(i, n - k);
                int lby = max(0LL, j - k + 1), upy = min(j, m - k);
                val.push_back((upx - lbx + 1) * (upy - lby + 1));
            }
        }
        sort(v.rbegin(), v.rend()), sort(val.rbegin(), val.rend());
        int ans = 0LL;
        for (int i = 0; i < w; i++)
            ans = ans + 0LL + (v[i] * val[i]);

        cout << ans << '\n';
    }
    return 0;
}