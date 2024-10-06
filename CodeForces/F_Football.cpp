#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, a, b, ans = 0;
    cin >> n >> a >> b;

    vector<pair<int, int>> vp(n);
    vp[0].first = a, vp[n - 1].second = b;
    for (int i = 0; i < n; i++)
    {
        if (vp[i].first == 0 && vp[i].second == 0)
        {
            if (vp[0].first > 1)
            {
                vp[i].first++;
                vp[0].first--;
            }
            else if (vp[n - 1].second > 1)
            {
                vp[i].second++;
                vp[n - 1].second--;
            }
        }
        if (vp[i].first == vp[i].second)
            ans++;
    }
    cout << ans << '\n';
    for (auto val : vp)
        cout << val.first << ':' << val.second << '\n';
    cout << '\n';

    return 0;
}