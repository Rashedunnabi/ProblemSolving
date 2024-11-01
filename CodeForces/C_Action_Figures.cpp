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
        string s;
        int n;
        cin >> n >> s;

        int ans = (1LL * n * (n + 1)) / 2;
        for (int j = n - 1, i = 0; j > i; j--)
        {
            if (s[j] == '1')
            {
                ans -= j + 1;
                i++;
            }
            else if (i > 0)
                i--;
        }
        cout << ans << '\n';
    }
    return 0;
}
