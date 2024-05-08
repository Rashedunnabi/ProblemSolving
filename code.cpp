#include <bits/stdc++.h>
using namespace std;
double findRoot(double x)
{
    double hi = max(1.0, x / 2), lo = 0, mid;
    for (int i = 0; i <= 64; i++)
    {
        mid = (hi + lo) / 2;
        if (mid * mid > x)
            hi = mid;
        else
            lo = mid;
    }
    return lo;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        double n;
        cin >> n;
        cout << fixed << setprecision(10) << findRoot(n) << '\n';
    }
    return 0;
}