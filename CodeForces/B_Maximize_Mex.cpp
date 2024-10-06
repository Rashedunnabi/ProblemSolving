#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, x, y, t = 1;
    cin >> t;
    while (t--)
    {
        int mex = 0;
        cin >> n >> x;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> y;
            mp[y]++;
        }
        for (; mex <= n; mex++)
        {
            if (mp[mex] == 0)
                break;
            mp[mex + x] += mp[mex] - 1;
        }
        cout << mex << '\n';
    }

    return 0;
}