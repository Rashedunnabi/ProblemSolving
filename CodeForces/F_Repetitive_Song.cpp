#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    map<string, int> mp;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (mp.find(s) == mp.end())
            mp[s] = i;
        else
        {
            ans = min(ans, i - mp[s]);
            mp[s] = i;
        }
    }
    ans == INT_MAX ? ans = 0 : ans = n - ans;
    cout << ans << '\n';
    return 0;
}