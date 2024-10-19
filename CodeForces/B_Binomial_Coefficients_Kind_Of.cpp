#include <bits/stdc++.h>
using namespace std;
#define int long long

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
    int N = 1e5 + 7, mod = 1e9 + 7;
    vector<int> powVal(N);
    for (int i = 1; i <= N; i++)
        powVal[i] = power(2, i, mod) % mod;

    int n, i;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            cout << 1 << '\n';
        else
            cout << powVal[b[i]] << '\n';
    }

    return 0;
}