#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, l, r, ans = 0, sum = 0;
        cin >> n >> l >> r;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        for (int i = 0, j = 0; j < n; ++j)
        {
            sum += v[j];

            while (i <= j && sum > r)
            {
                sum -= v[i];
                i++;
            }
            if (sum <= r && sum >= l)
            {
                i = j + 1;
                sum = 0;
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}