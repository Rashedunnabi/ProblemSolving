#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, x, y;
bool check(int mid)
{
    if (mid < min(x, y))
        return false;

    int cnt = 1;
    mid -= min(x, y);

    cnt += (mid / x) + (mid / y);
    return cnt >= n;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n >> x >> y;

    int lo = 0, hi = max(x, y) * (n + 1), mid;
    while (hi - lo > 1)
    {
        mid = lo + (hi - lo) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    cout << hi << '\n';

    return 0;
}