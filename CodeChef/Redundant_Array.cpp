#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        int ans = n;
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[v[i]].push_back(i);

        for (auto &val : mp)
        {
            int cost = 0;
            auto a = val.second;
            a.push_back(n);
            int last = -1;
            for (int i = 0; i < a.size(); i++)
            {
                int dif = a[i] - last - 1;
                if (dif > 0)
                    cost += (dif * val.first);
                last = a[i];
            }
            ans = min(ans, cost);
        }
        cout << ans << '\n';
    }
    return 0;
}
