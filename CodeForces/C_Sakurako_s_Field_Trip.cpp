#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        auto f = [&](int a, int b)
        {
            return v[a] == v[b];
        };
        int ans = 0, i = 0, j = n - 1;
        while (i < j)
        {
            if (i + 1 == j)
                ans += f(i, j);
            else if (i + 2 == j)
                ans += f(i, i + 1) + f(j - 1, j);
            else
            {
                int a = f(i, i + 1) + f(j, j - 1);
                int b = f(j, i + 1) + f(i, j - 1);
                ans += min(a, b);
            }
            i++, j--;
        }
        cout << ans << '\n';
    }
    return 0;
}