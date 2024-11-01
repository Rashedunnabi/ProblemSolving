#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(int mid, vector<int> &v)
{
    int f = 0, maxi = 0, n = v.size();
    for (int i = 1; i < n; i += 2)
    {
        if (v[i] - v[i - 1] > mid)
        {
            if (f)
                return false;
            f = 1;
            i--;
            continue;
        }
        maxi = max(maxi, v[i] - v[i - 1]);
    }
    return maxi <= mid;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;

        if (n == 1)
        {
            cout << 1 << '\n';
            continue;
        }

        if (n % 2 == 0)
        {
            int ans = INT_MIN;
            for (int i = 1; i < n; i += 2)
                ans = max(ans, v[i] - v[i - 1]);
            cout << ans << '\n';
        }
        else
        {
            int hi = v.back(), lo = 0;
            while (hi - lo > 1)
            {
                int mid = lo + (hi - lo) / 2;
                check(mid, v) ? hi = mid : lo = mid;
            }
            cout << hi << '\n';
        }
    }
    return 0;
}