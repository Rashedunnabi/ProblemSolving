#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int l, r, L, R, ans = 0;
        cin >> l >> r >> L >> R;

        ans = min(r, R) - max(l, L) + (l == L ? 0 : 1) + (r == R ? 0 : 1);
        if (min(r, R) < max(l, L))
            ans = 1;

        cout << ans << '\n';
    }
    return 0;
}