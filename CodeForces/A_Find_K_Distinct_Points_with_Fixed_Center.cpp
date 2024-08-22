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
        int xc, yc, k;
        cin >> xc >> yc >> k;

        if (k & 1)
        {
            cout << k * xc << ' ' << k * yc << '\n';
            for (int i = 1; i <= k / 2; i++)
            {
                cout << i << ' ' << i << '\n';
                cout << -i << ' ' << -i << '\n';
            }
        }
        else
        {
            int cnt = (k / 2) - 1;
            for (int i = 1; i <= cnt; i++)
            {
                cout << i << ' ' << i << '\n';
                cout << -i << ' ' << -i << '\n';
            }
            xc *= k, yc *= k;
            // cout << xc << " " << yc << '\n';

            cout << xc + 10000 << ' ' << yc + 10000 << '\n';
            cout << -10000 << ' ' << -10000 << '\n';
        }
        cout << '\n';
    }
    return 0;
}