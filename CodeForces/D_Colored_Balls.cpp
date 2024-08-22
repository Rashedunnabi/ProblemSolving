// 9876543210...???
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define endl "\n"

long long power(long long A, long long B)
{
    if (B == 0)
        return 1;
    long long ress = power(A, B / 2);
    if (B % 2)
        return ress * ress * A;
    else
        return ress * ress;
}

void primeFactors(ll ww)
{
    while (ww % 2 == 0)
    {
        ww = ww / 2;
    }
    for (ll ii = 3; ii <= sqrt(ww); ii = ii + 2)
    {
        while (ww % ii == 0)
        {
            ww = ww / ii;
        }
    }
}

const ll N = 5050, mod = 998244353;
ll a[N], dp[N] = {1};

void solve()
{
    ll n, i, j, x;
    cin >> n;

    for (i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + n + 1);
    ll ans = 0;

    for (i = 1, x; i <= n; i++)
    {
        x = a[i];
        for (j = 0; j <= x; j++)
            ans = (ans + dp[j] * x) % mod;
        for (j = x + 1; j < N; j++)
            ans = (ans + dp[j] * ((j + x + 1) / 2)) % mod;
        for (ll j = N; j--;)
        {
            if (j < x)
                continue;
            dp[j] = (dp[j] + dp[j - x]) % mod;
        }
    }
    cout << ans << endl;
}

int main()
{

    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
