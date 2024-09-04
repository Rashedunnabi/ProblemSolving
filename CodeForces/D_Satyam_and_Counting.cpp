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
        set<pair<int, int>> up, down;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (!y)
                down.insert({x, y});
            else
                up.insert({x, y});
        }
        int ans = 0;

        for (auto val : up)
        {
            int x = val.first, y = val.second;
            if (down.find({x, 0}) != down.end())
                ans += (down.size() - 1) + (up.size() - 1);

            if (down.find({x - 1, 0}) != down.end() && down.find({x + 1, 0}) != down.end())
                ans++;
        }

        for (auto val : down)
        {
            int x = val.first, y = val.second;
            if (up.find({x - 1, 1}) != up.end() && up.find({x + 1, 1}) != up.end())
                ans++;
        }

        cout << ans << '\n';
    }
    return 0;
}