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
        int n, i;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        for (int i = 0; i < n - 2; i++)
            v[n - 2] -= v[i];
        int ans = v[n - 1] - v[n - 2];
        cout << ans << '\n';
    }
    return 0;
}