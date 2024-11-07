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
        int n, ans = 0;
        cin >> n;

        ans = (n * n + 3) / 2;
        if (n % 2 == 0)
            ans = 2;
        cout << ans << '\n';
    }
    return 0;
}