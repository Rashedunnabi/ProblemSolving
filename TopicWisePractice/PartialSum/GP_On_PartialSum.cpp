#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 7, mod = 1e9 + 7;
int ar[N], rpow[N];

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n, ratio, q, i;
    cin >> n >> ratio >> q;

    rpow[1] = ratio;
    for (int i = 2; i < N; i++)
    {
        rpow[i] = rpow[i - 1] * ratio;
        rpow[i] %= mod;
    }

    for (i = 0; i < q; i++)
    {
        int a, l, r;
        cin >> a >> l >> r;

        ar[l] += a;
        ar[r + 1] -= (a * rpow[r - l + 1]);

        ar[l] %= mod;
        ar[r + 1] %= mod;
    }

    for (i = 1; i < N; i++)
    {
        ar[i] += (ar[i - 1] * ratio);
        ar[i] %= mod;
    }

    for (i = 1; i <= n; i++)
        cout << ar[i] << ' ';
    cout << '\n';

    return 0;
}