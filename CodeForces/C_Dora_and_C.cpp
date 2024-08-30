#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        int gc = __gcd(a, b);
        for (int i = 0; i < n; ++i)
            v[i] %= gc;

        sort(v.begin(), v.end());
        int ans = v.back() - v[0];

        for (int i = 0; i < n - 1; i++)
            ans = min(ans, v[i] + gc - v[i + 1]);

        cout << ans << '\n';
    }

    return 0;
}
