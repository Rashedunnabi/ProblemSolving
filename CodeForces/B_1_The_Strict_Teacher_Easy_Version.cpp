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
        int n, m, q;
        cin >> n >> m >> q;
        set<int> teacher;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            teacher.insert(x);
        }
        for (int i = 0; i < q; i++)
        {
            int x, ans = LONG_LONG_MAX;
            cin >> x;
            if (*teacher.begin() > x)
                ans = min(ans, *teacher.begin() - 1);
            else if (*teacher.rbegin() < x)
                ans = min(ans, n - *teacher.rbegin());
            else
            {
                auto it = teacher.lower_bound(x);
                int nxt = *it;
                int prv = *prev(it);
                int mid = (nxt + prv) / 2;
                ans = min(mid - prv, nxt - mid);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}