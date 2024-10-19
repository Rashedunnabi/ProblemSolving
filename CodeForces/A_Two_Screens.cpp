#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int i = 0, j = 0, ans = 0, c = 0;
        string s, t;
        cin >> s >> t;

        while (i < s.length() && j < t.length())
        {
            if (s[i] == t[j])
            {
                ans++;
                i++, j++;
                c = 1;
            }
            else
            {
                break;
            }
        }
        ans += (s.length() - i);
        ans += (t.length() - i);
        if (c)
            ans++;
        cout << ans << '\n';
    }
    return 0;
}