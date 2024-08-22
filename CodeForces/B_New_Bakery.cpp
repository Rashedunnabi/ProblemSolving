#include <bits/stdc++.h>
using namespace std;
#define int long long

int func(int n, int a, int b, int k)
{
    int firstHalf = k * 1LL * b - (k * 1LL * (k - 1) / 2);
    int secondHalf = (n - k) * a;
    return firstHalf + secondHalf;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, a, b, k, i;
        cin >> n >> a >> b;
        k = max(0LL, min(b + 1 - a, n));
        int ans = (n * 1LL * a);
        ans = max(ans, func(n, a, b, k));
        cout << ans << '\n';
    }
    return 0;
}