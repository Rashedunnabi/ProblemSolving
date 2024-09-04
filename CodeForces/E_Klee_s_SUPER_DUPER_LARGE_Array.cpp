#include <bits/stdc++.h>
using namespace std;
#define int long long

int value(int n)
{
    return 1LL * n * (n + 1) / 2;
}
int func(int mid, int n, int k)
{
    int val1 = value(mid) - value(k - 1);
    int val2 = value(n + k - 1) - value(mid);
    return abs(val1 - val2);
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int lo = k, hi = k + n - 1;
        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (func(mid, n, k) > func(mid + 1, n, k))
                lo = mid;
            else
                hi = mid;
        }
        cout << min(func(lo, n, k), func(hi, n, k)) << '\n';
    }
    return 0;
}