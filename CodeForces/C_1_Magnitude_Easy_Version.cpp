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
        int n, ans = 0, sum = 0;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        for (int i = 0; i < n; i++)
        {
            sum += v[i];
            ans = max(ans + v[i], abs(sum));
        }
        cout << ans << '\n';
    }
    return 0;
}