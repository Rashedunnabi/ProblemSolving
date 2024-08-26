#include <bits/stdc++.h>
using namespace std;
int ans, n, q;
bool isCommon(string &a, string &b)
{
    return a[0] == b[0] || a[0] == b[1] || a[1] == b[0] || a[1] == b[1];
}
int disCal(set<int> &s, int l, int r, set<int>::iterator &it)
{
    if (it != s.end())
        ans = min(ans, abs(*it - l) + abs(*it - r));
    if (it != s.begin())
        ans = min(ans, abs(*prev(it) - l) + abs(*prev(it) - r));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        vector<string> v;
        map<string, set<int>> mp;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            sort(s.begin(), s.end());
            v.push_back(s);
            mp[s].insert(i);
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            string a = v[l], b = v[r];
            if (isCommon(a, b))
            {
                cout << abs(l - r) << '\n';
                continue;
            }
            ans = INT_MAX;
            for (auto &val : mp)
            {
                if (val.first == a || val.first == b)
                    continue;
                set<int> &s = val.second;
                auto it = s.lower_bound(l);
                ans = min(ans, disCal(s, l, r, it));
                it = s.lower_bound(r);
                ans = min(ans, disCal(s, l, r, it));
            }
            cout << (ans == INT_MAX ? -1 : ans) << '\n';
        }
    }
    return 0;
}