#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int i, n, x, y, ans = 0;
        cin >> n >> x >> y;
        vector<int> v(x);
        for (int &e : v)
        {
            cin >> e;
            e--;
        }
        sort(v.begin(), v.end());
        vector<pair<int, int>> vp;
        for (i = 0; i < x; i++)
        {
            int cur = ((v[(i + 1) % x] + n - v[i]) % n) - 1;
            vp.push_back({2 - (cur % 2), cur});
        }
        sort(vp.begin(), vp.end());

        for (auto p : vp)
        {
            if (y >= p.second / 2)
            {
                ans += p.second;
                y -= (p.second / 2);
            }
            else
            {
                ans += (2 * y);
                y = 0;
            }
        }
        cout << ans + x - 2 << '\n';
    }
    return 0;
}