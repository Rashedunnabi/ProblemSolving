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
        int n, k, i, sum = 0, ans = 0;
        cin >> n >> k;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        for (int i = 0; i < n; i++)
        {
            if (v[i] >= k)
                sum += v[i];
            if (v[i] == 0)
            {
                if (sum > 0)
                {
                    ans++;
                    sum--;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}