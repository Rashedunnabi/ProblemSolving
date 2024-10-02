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
        int n, i, mx1 = -1, mx2 = -1, m1 = 0, m2 = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (i & 1)
            {
                m1++;
                mx1 = max(mx1, x);
            }
            else
            {
                m2++;
                mx2 = max(mx2, x);
            }
        }
        int ans = max(m1 + mx1, m2 + mx2);
        cout << ans << '\n';
    }
    return 0;
}