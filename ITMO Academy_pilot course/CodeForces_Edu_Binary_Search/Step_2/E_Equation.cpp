#include <bits/stdc++.h>
using namespace std;
double findRoot(double x)
{
    double hi = x, lo = 0, mid;
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

double equation(double x)
{
    double ans = (x * x) + findRoot(x);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    double n;
    cin >> n;

    double lo = 0.0, hi = n, mid;
    for (int i = 0; i < 200; i++)
    {
        mid = (hi + lo) / 2;
        if (equation(mid) > n)
            hi = mid;
        else
            lo = mid;
    }

    cout << fixed << setprecision(15) << lo << '\n';

    return 0;
}