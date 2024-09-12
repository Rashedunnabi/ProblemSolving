#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    set<int> st;
    st.insert(4), st.insert(8), st.insert(15);
    st.insert(16), st.insert(23), st.insert(42);
    map<int, set<int>> mp;

    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (st.find(x) == st.end())
        {
            ans++;
            continue;
        }
        mp[x].insert(i);
    }

    for (auto v : mp)
    {
        cout << v.first << ": ";
        for (auto val : v.second)
            cout << val << ' ';
        cout << '\n';
    }

    int c = 0;
    for (int ind : mp[4])
    {
        int cnt = 0, x = ind;
        for (auto &val : mp)
        {
            if (val.first == 4)
                continue;
            set<int> &s = val.second;
            if (s.lower_bound(x) != s.end())
            {
                cnt++;
                int tmp = *s.lower_bound(x);
                s.erase(s.lower_bound(x));
                x = tmp;
            }
            else
                break;
        }
        if (cnt != 6)
        {
            ans += cnt;
            break;
        }
        c += 6;
    }

    for (auto val : mp)
        ans += val.second.size();
    ans -= c;
    cout << ans << '\n';

    return 0;
}