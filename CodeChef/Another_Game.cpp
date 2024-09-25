#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i, ans = 0;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (i + 1 == x)
                continue;
            v.push_back(x);
        }
        if (v.size())
        {
            int mx = *max_element(v.begin(), v.end());
            ans = mx + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}