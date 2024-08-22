#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    map<int, int> mp;
    int l = 0, cnt = 0, ans = 0;
    for (int r = 0; r < n; r++)
    {
        mp[v[r]]++;
        if (mp[v[r]] == 1)
            cnt++;
        while (cnt > k)
        {
            mp[v[l]]--;
            if (mp[v[l]] == 0)
                cnt--;
            l++;
        }
        ans += (r - l + 1);
    }
    cout << ans << '\n';

    return 0;
}