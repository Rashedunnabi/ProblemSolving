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
        int n, m, destination, power = 1;
        cin >> n >> m >> destination;

        vector<pair<int, int>> vp(n), point(m);
        for (int i = 0; i < n; i++)
            cin >> vp[i].first >> vp[i].second;

        for (int i = 0; i < m; i++)
            cin >> point[i].first >> point[i].second;

        int j = 0, ans = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++)
        {
            int dif = vp[i].second - vp[i].first;
            while (j < m)
            {
                if (point[j].first >= vp[i].first)
                    break;
                pq.push(point[j].second);
                j++;
            }
            while (!pq.empty() && power < dif + 2)
            {
                power += pq.top();
                pq.pop();
                ans++;
            }
            if (power < dif + 2)
            {
                ans = -1;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}