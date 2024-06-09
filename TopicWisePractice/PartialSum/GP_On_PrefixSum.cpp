#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7, mod = 1e9 + 7;
int ar[N], inv[N], preSum[N], pw[N];

long long power(long long a, long long b, long long m = 1e9 + 7)
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

void calculateInverse(int k)
{
    inv[1] = power(k, mod - 2);
    pw[0] = 1, pw[1] = k;
    for (int i = 2; i < N; i++)
    {
        inv[i] = (inv[i - 1] * inv[1]) % mod;
        pw[i] = (pw[i - 1] * k) % mod;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k, i;
    cin >> n >> k;

    calculateInverse(k);

    for (i = 1; i <= n; i++)
        cin >> ar[i];

    for (i = 1; i <= n; i++)
        preSum[i] = (preSum[i - 1] + (ar[i] * pw[i])) % mod;

    int q;
    cin >> q;
    while (q--)
    {
        int l, r, ans = 0;
        cin >> l >> r;
        ans = (inv[l] * (preSum[r] - preSum[l - 1])) % mod;
        cout << ans << '\n';
    }

    return 0;
}