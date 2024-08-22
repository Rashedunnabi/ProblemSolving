#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m;
    string txt, pat;
    cin >> n >> m >> txt >> pat;

    vector<int> mp(27);
    for (auto it : pat)
        mp[it - 'a']++;

    int l = 0, r = 0, ans = 0;
    for (r = 0; r < n; r++)
    {
        if (mp[txt[r] - 'a'] > 0)
        {
            mp[txt[r] - 'a']--;
            ans += r - l + 1;
        }
        else
        {
            while (mp[txt[r] - 'a'] <= 0)
            {
                mp[txt[l] - 'a']++;
                l++;
            }
            if (mp[txt[r] - 'a'] > 0)
            {
                mp[txt[r] - 'a']--;
                ans += r - l + 1;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}