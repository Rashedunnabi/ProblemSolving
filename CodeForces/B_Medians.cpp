#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        if (n == 1)
        {
            if (k == 1)
            {
                cout << 1 << '\n';
                cout << 1 << '\n';
            }
            else
                cout << -1 << '\n';
            continue;
        }

        if (k & 1)
        {
            int left = k - 1;
            int right = k + 2;
            if (left <= 0 || right > n)
                cout << -1 << '\n';
            else
            {
                cout << 3 << '\n';
                cout << 1 << ' ' << left << ' ' << right << '\n';
            }
        }
        else
        {
            int left = k - 1;
            int right = k + 1;
            if (left <= 0 || right > n)
                cout << -1 << '\n';
            else
            {
                cout << 3 << '\n';
                cout << 1 << ' ' << k << ' ' << right << '\n';
            }
        }
    }
    return 0;
}