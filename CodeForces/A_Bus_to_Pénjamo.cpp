#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pii pair<int, int>
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, r, i, rem = 0, ans = 0;
        cin >> n >> r;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            int div = x / 2;
            int remi = x % 2;
            r -= div;
            rem += remi;
            ans += (div * 2);
        }
        if (rem <= r)
            ans += rem;
        else if (r != 0 && rem / r != 2)
            ans += (r - rem % r);

        cout << ans << '\n';
    }
    return 0;
}