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
        int n, i, sum = INT_MIN, ans = -1;
        cin >> n;
        for (i = 2; i <= n; i++)
        {
            int s = 0;
            for (int j = 1; j * i <= n; j++)
            {
                s += (i * j);
            }
            if (s > sum)
            {
                ans = i;
                sum = s;
            }
        }
        // cout << sum << ' ';
        cout << ans << '\n';
    }
    return 0;
}