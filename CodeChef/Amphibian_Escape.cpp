#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k, h, ans = 0;
        cin >> n >> k >> h;

        for (int i = 1; i <= n; i++)
        {
            int x = (h + k - 1) / k;
            x += i;

            if (i >= h)
                ans += n;
            else
                ans += max(0LL, n - x + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}