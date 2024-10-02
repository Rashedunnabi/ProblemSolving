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
        int x;
        cin >> x;
        int lo = 1, hi = 2e18 + 7, ans = 0;
        while (hi >= lo)
        {
            int mid = lo + (hi - lo) / 2;
            int p = sqrtl(mid);
            while (p * 1LL * p > mid)
                p--;
            while ((p + 1) * 1LL * (p + 1) <= mid)
                p++;
            int val = mid - p;
            if (val >= x)
                hi = mid - 1, ans = mid;
            else
                lo = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}