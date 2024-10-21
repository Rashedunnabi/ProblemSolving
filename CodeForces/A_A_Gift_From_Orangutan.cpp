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
        int n, i;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        int mini = *min_element(all(v));
        int maxi = *max_element(all(v));
        int ans = (maxi - mini) * (n - 1);
        cout << ans << '\n';
    }
    return 0;
}