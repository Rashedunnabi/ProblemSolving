#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, sum = 0, mx = 0;
        cin >> n >> k;
        int ans = 1;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            sum += x;
            mx = max(x, mx);
        }
        sum += k;
        int res = sum / mx, rem = sum % res;
        while (rem > k)
        {
            res--;
            rem = sum % res;
        }
        ans = min(res, n);
        cout << ans << "\n";
    }
    return 0;
}