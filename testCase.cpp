#include <bits/stdc++.h>
#define int long long
#define N 100005
using namespace std;
int n, a[N], f[N], l, r, ans, q[N];
bool OK(int lmt)
{
    int L = 1, R = 1;
    q[R] = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        while (L <= R && a[q[L]] < a[i - 1] - lmt)
            L++;
        f[i] = a[i] - a[i - 1] + f[q[L]];
        while (L <= R && f[q[R]] >= f[i])
            --R;
        q[++R] = i;
    }
    return f[n + 1] <= lmt;
}
void solve()
{
    cin >> n, l = 0, r = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], l = max(l, a[i]), a[i] += a[i - 1];
    a[n + 1] = ans = r = a[n];
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (OK(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}