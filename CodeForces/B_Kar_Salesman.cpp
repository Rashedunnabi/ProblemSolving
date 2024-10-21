#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k, maxi = 0, sum = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            maxi = max(maxi, x);
            sum += x;
        }
        int ans = max(maxi, (sum + k - 1) / k);
        cout << ans << '\n';
    }
    return 0;
}