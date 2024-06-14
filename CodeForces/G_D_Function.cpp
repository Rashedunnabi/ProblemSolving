#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
long long power(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int l, r, k;
        cin >> l >> r >> k;

        int x = (10 / k) + (10 % k != 0);
        int ans = (power(x, r, MOD) - power(x, l, MOD) + MOD) % MOD;
        if (k > 9)
            ans = 0;
        cout << ans << '\n';
    }
    return 0;
}