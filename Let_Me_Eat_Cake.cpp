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
        int a, b, ans = 0;
        cin >> a >> b;

        while (a != b)
        {
            if (a < b)
                swap(a, b);
            ans += ((a + 1) / 2);
            a /= 2;
        }
        cout << ans << '\n';
    }
    return 0;
}