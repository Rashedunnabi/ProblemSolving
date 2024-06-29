#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;

        int n = s.length(), m = t.length();
        int ans = n + m;

        for (int k = 0; k < m; k++)
        {
            int i = 0, j = k, match = 0; // i upore point kore j niche
            while (i < n && j < m)
            {
                while (s[i] != t[j] && i < n)
                    i++;
                if (s[i] == t[j])
                    match++, i++, j++;
            }
            int tmp = n + m - match;
            ans = min(ans, tmp);
        }
        cout << ans << '\n';
    }
    return 0;
}
