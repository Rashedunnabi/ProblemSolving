#include <bits/stdc++.h>
using namespace std;
#define int long long

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return max(a.first, a.second) < max(b.first, b.second);
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> vp(n);
        for (int i = 0; i < n; ++i)
        {
            int a, b;
            cin >> a >> b;
            vp[i] = {a, b};
        }
        sort(vp.begin(), vp.end(), cmp);
        for (auto &val : vp)
            cout << val.first << " " << val.second << " ";
        cout << "\n";
    }
    return 0;
}
