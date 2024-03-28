#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        pair<ll, int> ans = {0, 0};
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for (int i = n; i > 0; i--)
        {
            q.push(a[b[i]]);
            while (q.size() > i)
                q.pop();
            if (q.size() == i)
                ans = max(ans, make_pair(q.top() * i, -i));
        }
        cout << ans.first << " " << -ans.second << "\n";
    }
}