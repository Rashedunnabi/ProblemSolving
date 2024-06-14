#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int x, y, z, k, ans = 0;
        cin >> x >> y >> z >> k;

        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                int mul = i * j;
                int expected_height = k / mul;
                if (k % mul == 0)
                {
                    if (expected_height <= z)
                    {
                        int tot_x = x - i + 1;
                        int tot_y = y - j + 1;
                        int tot_z = z - expected_height + 1;
                        ans = max(ans, tot_x * tot_y * tot_z);
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
