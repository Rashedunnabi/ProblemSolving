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
        int x, y, k;
        cin >> x >> y >> k;

        int ans = 0;
        int dx = (x + k - 1) / k;
        int dy = (y + k - 1) / k;
        ans = dx + dy + abs(dx - dy);
        if (dx > dy)
            ans--;

        cout << ans << '\n';
    }
    return 0;
}