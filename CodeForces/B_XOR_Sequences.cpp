#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int x, y, i;
        cin >> x >> y;

        int num = x ^ y;
        int lastInd = 0;
        for (i = 0; i < 32; i++)
        {
            if ((num >> i) & 1LL)
            {
                lastInd = i;
                break;
            }
        }
        int ans = 1LL << lastInd;
        cout << ans << '\n';
    }
    return 0;
}