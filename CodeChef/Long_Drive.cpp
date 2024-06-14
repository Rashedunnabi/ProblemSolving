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

        int x, y;
        cin >> x >> y;
        int up = (10 * y) - (10 * x);
        int down = 100 - y;
        int ans = up / down;

        if (up % down)
            ans++;
        cout << ans << '\n';
    }
    return 0;
}