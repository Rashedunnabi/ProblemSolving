#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, s, m, i;
        cin >> n >> s >> m;
        bool flag = false;
        vector<pair<int, int>> vp(n);
        for (auto &i : vp)
            cin >> i.first >> i.second;
        if (vp[0].first >= s || m - vp[n - 1].second >= s)
            flag = true;
        for (i = 0; i < n - 1; i++)
        {
            int dif = vp[i + 1].first - vp[i].second;
            if (dif >= s)
                flag = true;
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}