#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    int lo = 0, hi = 1e9 + 10;
    while (hi - lo > 1)
    {
        int mid = lo + (hi - lo) / 2;

        int value = mid * 1LL * (mid + 1) / 2;
        if (value <= n)
            lo = mid;
        else
            hi = mid;
    }
    cout << lo << '\n';
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}