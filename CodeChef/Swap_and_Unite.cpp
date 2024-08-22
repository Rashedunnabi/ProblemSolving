#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int i, j, n;
        string s;
        cin >> s;
        n = s.length();
        map<char, int> mp;

        for (i = 0; i < n; i++)
            mp[s[i]]++;

        int ans = INT_MAX;

        for (auto val : mp)
        {
            char ch = val.first;
            int fre = val.second;
            int cnt = 0;
            for (i = 0; i < fre; i++)
            {
                if (s[i] == ch)
                    cnt++;
            }
            i = 0, j = fre - 1;
            while (j < n)
            {
                ans = min(ans, abs(fre - cnt));
                i++, j++;
                if (s[i - 1] == ch)
                    cnt--;
                if (j < n && s[j] == ch)
                    cnt++;
            }
            ans = min(ans, abs(fre - cnt));
        }
        cout << ans << '\n';
    }
    return 0;
}