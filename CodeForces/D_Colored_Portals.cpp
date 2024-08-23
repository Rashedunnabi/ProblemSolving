#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isCommon(const string &a, const string &b)
{
    return a[0] == b[0] || a[0] == b[1] || a[1] == b[0] || a[1] == b[1];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<string> v(n);
        map<string, vector<int>> mp;

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            sort(s.begin(), s.end());
            v[i] = s;
            mp[s].push_back(i);
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            string a = v[l], b = v[r];
            if (isCommon(a, b))
            {
                cout << abs(r - l) << '\n';
                continue;
            }

            int ans = LLONG_MAX;
            for (const auto &x : mp)
            {
                const auto &st = x.second;
                if (x.first == a || x.first == b)
                    continue;

                auto it = lower_bound(st.begin(), st.end(), l);
                if (it != st.end())
                    ans = min(ans, abs(l - *it) + abs(*it - r));
                if (it != st.begin())
                {
                    --it;
                    ans = min(ans, abs(l - *it) + abs(*it - r));
                }

                it = lower_bound(st.begin(), st.end(), r);
                if (it != st.end())
                    ans = min(ans, abs(r - *it) + abs(*it - l));
                if (it != st.begin())
                {
                    --it;
                    ans = min(ans, abs(r - *it) + abs(*it - l));
                }
            }
            cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
        }
    }
    return 0;
}