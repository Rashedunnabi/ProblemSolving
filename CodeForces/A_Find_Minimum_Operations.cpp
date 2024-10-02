#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k, x = 10;
        cin >> n >> k;
        if (k == 1)
        {
            cout << n << '\n';
            continue;
        }
        int ans = 0;
        while (n != 0)
        {
            int rem = n % k;
            n = (n / k);
            ans += rem;
        }
        cout << ans << '\n';
    }
    return 0;
}