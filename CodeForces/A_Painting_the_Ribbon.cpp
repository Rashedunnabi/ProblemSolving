// 9876543210...???
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl "\n"
ll n, x, i, p, q, ans, y, l, r, qr, m, a, b, c, j, k;
string s;

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

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;

    ll value = n / m, rem = n % m;
    ll ans = (m - 1) * value + max(rem - 1, 0LL);
    if (ans > k)
        yes;
    else
        no;
}

int main()
{

    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
