#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        string s;
        cin >> n >> s;

        set<int> a, b, c;
        for (i = 0; i < n; i++)
        {
            if (s[i] == 'a')
                a.insert(i);
            if (s[i] == 'b')
                b.insert(i);
            if (s[i] == 'c')
                c.insert(i);
        }

        int ans = 0;
        for (i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                auto it = b.lower_bound(i);
                if (it == b.end())
                    break;
                auto iit = c.lower_bound(*it);
                if (iit == c.end())
                    break;
                ans++;
                c.erase(iit);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}