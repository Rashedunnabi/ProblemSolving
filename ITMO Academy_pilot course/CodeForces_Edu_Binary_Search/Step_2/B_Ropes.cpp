#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &a, int k, double x)
{
    if (x == 0)
        return true;
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i)
        cnt += a[i] / x;
    return cnt >= k;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    double lo = 0, hi = 1e10, mid;
    int lp = 100;
    while (lp--)
    {
        mid = lo + (hi - lo) / 2;
        if (check(a, k, mid))
            lo = mid;
        else
            hi = mid;
    }
    // cout << fixed << setprecision(8) << lo << '\n';
    printf("%.6lf\n", lo);
    return 0;
}
