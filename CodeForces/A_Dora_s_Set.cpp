#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = l; i <= r - 2; i++)
        {
            if (i & 1)
            {
                ans++;
                i += 2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}