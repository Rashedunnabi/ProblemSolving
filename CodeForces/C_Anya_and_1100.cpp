#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string s;
        int q, cnt = 0;
        cin >> s >> q;
        s = '$' + s;

        auto check = [&](string &s, int i)
        {
            return i < s.size() - 3 && s.substr(i, 4) == "1100";
        };

        for (int i = 1; i < (int)s.size() - 3; i++)
            cnt += check(s, i);

        while (q--)
        {
            int i, v;
            cin >> i >> v;

            if (s[i] - '0' == v)
            {
                cout << (cnt > 0 ? "YES" : "NO") << '\n';
                continue;
            }

            int st = max(0, i - 3), en = min((int)s.size() - 4, i);
            for (int j = st; j <= en; ++j)
                cnt -= (check(s, j));

            s[i] = v + '0';
            for (int j = st; j <= en; ++j)
                cnt += (check(s, j));

            cout << (cnt > 0 ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}