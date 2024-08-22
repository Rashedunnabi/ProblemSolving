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
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n), b(n);

        map<int, int> mp;
        for (int &i : a)
        {
            cin >> i;
            i %= m;
        }
        for (int &i : b)
        {
            cin >> i;
            i %= m;
            mp[i]++;
        }
        int ans = 0;
        for (auto val : a)
        {
            int x = m - val;
            if (val == 0)
                ans += mp[val];
            else
                ans += mp[x];
        }
        cout << ans << '\n';
    }
    return 0;
}