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
        bool flag = true;
        int i = 0, j = 0, n = s.length(), m = t.length();
        while (i < n && j < m)
        {
            if (s[i] == '?' || s[i] == t[j])
                s[i++] = t[j++];
            else
                i++;
        }
        if (i >= n && j < m)
            cout << "NO\n";
        else
        {
            while (i < n)
                (s[i] == '?') ? s[i++] = 'a' : i++;
            cout << "YES\n"
                 << s << '\n';
        }
    }
    return 0;
}