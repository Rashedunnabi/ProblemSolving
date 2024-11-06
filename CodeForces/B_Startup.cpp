#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.rbegin(), v.rend()

int longestKSubstr(string s, int k)
{
    map<char, int> mp;
    int l = 0, n = s.length(), maxi = -1, cnt = 0;
    for (int r = 0; r < n; r++)
    {
        mp[s[r]]++;
        if (mp[s[r]] == 1)
            cnt++;
        while (cnt > k)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
                cnt--;
            l++;
        }
        maxi = max(r - l + 1, maxi);
    }
    return maxi;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(k + 1);

        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            v[x] += y;
        }

        sort(all(v));
        int sum = 0LL;
        for (int i = 0; i < min(n, k); i++)
            sum += v[i];
        cout << sum << '\n';
    }
    return 0;
}