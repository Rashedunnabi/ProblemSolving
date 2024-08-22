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
        int n, k, i;
        cin >> n >> k;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        sort(v.rbegin(), v.rend());

        int alice = 0LL, bob = 0LL;

        for (i = 0; i < (n / 2) * 2; i++)
            (i & 1) ? bob += (v[i] + 0LL) : alice += (v[i] + 0LL);

        int ans = max(0LL, alice - bob - k);
        if (n & 1)
            ans += v[n - 1];

        cout << ans << '\n';
    }
    return 0;
}