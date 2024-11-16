#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        double s = (a + b + c) / 2.0;
        double area = sqrt(s * (s - a) * (s - b) * (s - c));
        double r = area / s;
        double l2 = r * r;
        int num = round(l2 * s * s);
        int den = round(s * s);
        int div = __gcd(num, den);
        num /= div;
        den /= div;
        cout << num << "/" << den << '\n';
    }
    return 0;
}