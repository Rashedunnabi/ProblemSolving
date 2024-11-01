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
        int n, m, r, c, ans = 0;
        cin >> n >> m >> r >> c;
        int upore = m - c;
        int niche = (n - r) * (2 * m - 1);
        ans = upore + niche;
        cout << ans << '\n';
    }
    return 0;
}