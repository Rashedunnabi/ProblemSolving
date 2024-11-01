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
        int n, m, r, c, ans;
        cin >> n >> m >> r >> c;
        int up = m - c;
        int down = (n - r) * (2 * m - 1);
        ans = up + down;
        cout << ans << '\n';
    }
    return 0;
}