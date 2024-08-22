#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i, ans = 0;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        for (i = 0; i < n - 1; i++)
            ans = max(ans, v[i] + v.back());
        cout << ans << '\n';
    }
    return 0;
}