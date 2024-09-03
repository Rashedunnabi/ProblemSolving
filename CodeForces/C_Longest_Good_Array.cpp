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
        int l, r, ans = 0;
        cin >> l >> r;

        for (int i = 0;; i++)
        {
            int val = (i + 1) * 1LL * i / 2;
            if (l + val <= r)
                ans = i + 1;
            else
                break;
        }
        cout << ans << '\n';
    }
    return 0;
}