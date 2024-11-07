#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
int modInverseFermat(int b, int M)
{
    int result = 1;
    int exp = M - 2;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (1LL * result * b) % M;
        b = (1LL * b * b) % M;
        exp /= 2;
    }
    return result;
}

int modInverseEuclid(int b, int M)
{
    int x = 1, y = 0;
    int m = M, temp, q;
    while (b > 1)
    {
        q = b / m;
        temp = m;
        m = b % m, b = temp;
        temp = y;
        y = x - q * y;
        x = temp;
    }
    if (x < 0)
        x += M;
    return x;
}
int modDivide(int a, int b, int M)
{
    int b_inv = modInverseFermat(b, M);
    return (1LL * a * b_inv) % M;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        //(d+1)/2d
        int n, d;
        cin >> n >> d;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
        }
        int p = modDivide(d + 1, 2 * d, MOD);
        cout << p << '\n';
    }
    return 0;
}