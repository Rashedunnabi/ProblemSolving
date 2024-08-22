#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 20, mod = 1e9 + 7;
int n, k, a[N], cnt[2];
int fact[N], inv[N];

inline int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

void preCalculation()
{
    fact[0] = inv[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = 1ll * fact[i - 1] * i % mod;
        inv[i] = power(fact[i], mod - 2);
    }
}

inline int nCr(int n, int r)
{
    if (r > n)
        return 0;
    return 1ll * fact[n] * inv[r] % mod * inv[n - r] % mod;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    preCalculation();

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cnt[0] = cnt[1] = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int ans = 0;
        for (int t = (k + 1) / 2; t <= k; t++)
        {
            int res = 1ll * nCr(cnt[0], k - t) * nCr(cnt[1], t) % mod;
            ans = (ans + res) % mod;
        }
        cout << ans << '\n';
    }
}
