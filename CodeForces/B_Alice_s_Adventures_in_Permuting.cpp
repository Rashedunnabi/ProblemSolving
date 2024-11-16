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
        int n, b, c, ans = 0;
        cin >> n >> b >> c;

        if (b == 0)
        {
            if (c >= n)
                ans = n;
            else if (c >= max(0LL, n - 2))
                ans = n - 1;
            else
                ans = -1;
        }
        else
        {
            int x = (n - c + b - 1) / b;
            ans = n - max(x, 0LL);
        }

        cout << ans << '\n';
    }
    return 0;
}