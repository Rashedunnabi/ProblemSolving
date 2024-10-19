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
        int n, k, ans = 1;
        cin >> n >> k;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;

        sort(v.begin(), v.end());
        for (int l = 0, r = 0; r < n; r++)
        {
            while (l + 1 < n && v[r] - v[l] >= k)
                l++;

            if (r > 0 && v[r] - v[r - 1] < 2)
                ans = max(ans, r - l + 1);
            else
                l = r;
        }
        cout << ans << '\n';
    }
    return 0;
}