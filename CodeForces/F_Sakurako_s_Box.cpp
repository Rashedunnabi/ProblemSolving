#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

long long power(long long a, long long b, long long m = mod)
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
        int n, i;
        cin >> n;
        vector<int> v(n), preSum(n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            preSum[i + 1] = (v[i] + preSum[i]) % mod;
        }
        int cnt = n * (n - 1) / 2;
        int down = power(cnt, mod - 2);
        int up = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int x = v[i] * 1LL * (preSum[n] - preSum[i + 1] + mod) % mod;
            up = (up + x) % mod;
        }
        int ans = (up * down) % mod;
        cout << ans << '\n';
    }
    return 0;
}