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
        int n, x, y;
        cin >> n >> x >> y;
        x = min(x, y);
        int ans = (n + x - 1) / x;
        cout << ans << '\n';
    }
    return 0;
}