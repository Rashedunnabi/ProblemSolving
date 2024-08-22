#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, k, i;
    cin >> n >> k;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    if (k == 1)
    {
        for (auto val : v)
            cout << val << ' ';
        cout << '\n';
        return 0;
    }
    if (k == 2)
    {
        for (i = 0; i < n - 1; i++)
            cout << min(v[i], v[i + 1]) << ' ';
        cout << '\n';
        return 0;
    }

    set<pair<int, int>> s1, s2;
    vector<pair<int, int>> vp;

    for (i = 0; i < k; i++)
        vp.push_back({v[i], i});
    sort(vp.begin(), vp.end());

    int mid = (k - 1) / 2;
    for (i = 0; i <= mid; i++)
        s1.insert(vp[i]);
    for (i = mid + 1; i < k; i++)
        s2.insert(vp[i]);

    vector<int> ans;
    ans.push_back(s1.rbegin()->first);

    for (i = 0; i + k < n; i++)
    {
        if (s1.find({v[i], i}) != s1.end())
        {
            s1.erase({v[i], i});
            int val = s1.rbegin()->first;
            if (v[i + k] > val)
            {
                s2.insert({v[i + k], i + k});
                auto it = s2.begin();
                s1.insert(*it);
                s2.erase(*it);
            }
            else
            {
                s1.insert({v[i + k], i + k});
            }
        }
        else
        {
            s2.erase({v[i], i});
            int val = s1.rbegin()->first;
            if (v[i + k] > val)
            {
                s2.insert({v[i + k], i + k});
            }
            else
            {
                s1.insert({v[i + k], i + k});
                auto it = s1.rbegin();
                s2.insert(*it);
                s1.erase(*it);
            }
        }
        auto it = s1.rbegin();
        ans.push_back(it->first);
    }

    for (auto val : ans)
        cout << val << ' ';
    cout << '\n';
    return 0;
}