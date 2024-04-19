#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, k, i, ans = 0;
        cin >> n >> m >> k;
        vector<int> a(n), b(m);
        map<int, int> fa, fb;

        for (auto &e : a)
            cin >> e;
        for (auto &e : b)
            cin >> e, fb[e]++;

        for (i = 0; i < m; i++)
            fa[a[i]]++;

        int cnt = 0;
        for (auto val : fb)
            cnt += min(val.second, fa[val.first]);
        if (cnt >= k)
            ans++;

        for (i = m; i < n; i++)
        {
            if (a[i] == a[i - m])
            {
                if (cnt >= k)
                    ans++;
                continue;
            }
            fa[a[i]]++, fa[a[i - m]]--;
            if (fa[a[i]] <= fb[a[i]])
                cnt++;
            if (fa[a[i - m]] < fb[a[i - m]])
                cnt--;
            if (cnt >= k)
                ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}