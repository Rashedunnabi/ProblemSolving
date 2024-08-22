#include <bits/stdc++.h>
using namespace std;
int f[300005];
int mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    f[0] = 1, f[1] = 1;
    for (int i = 2; i <= 300000; i++)
        f[i] = (2ll * (i - 1) * f[i - 2] + f[i - 1]) % mod;

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int tmp = 0, x, y;
        for (int i = 1; i <= k; i++)
        {
            cin >> x >> y;
            if (x == y)
                tmp++;
            else
                tmp += 2;
        }
        cout << f[n - tmp] << "\n";
    }
}