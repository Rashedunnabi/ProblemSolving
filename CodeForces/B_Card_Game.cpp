#include <bits/stdc++.h>
using namespace std;

int func(int a, int b, int c, int d)
{
    int cnt = (a >= b && c >= d && !(a == b && c == d));
    return 2 * cnt;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = func(a, c, b, d);
        ans += func(a, d, b, c);
        cout << ans << '\n';
    }
    return 0;
}