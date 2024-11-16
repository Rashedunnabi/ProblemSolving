#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, ans = INT_MAX;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;

        for (int i = 0; i < n; i++)
        {
            int fst = i, lst = i;
            while (lst < n && v[fst] == v[lst])
                lst++;
            ans = min(ans, n - (lst - fst));
        }
        cout << ans << '\n';
    }
    return 0;
}