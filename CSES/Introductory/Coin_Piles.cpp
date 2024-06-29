#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int a, b, x, y;
        cin >> x >> y;
        a = (2 * 1LL * x - y) / 3;
        b = (2 * 1LL * y - x) / 3;
        int xx = 2 * 1LL * a + b;
        int yy = a + 2 * 1LL * b;

        if (xx == x && yy == y && a >= 0 && b >= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}