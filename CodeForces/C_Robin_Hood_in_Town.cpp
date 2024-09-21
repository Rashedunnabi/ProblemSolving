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
        int n, sum = 0, maxi = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            sum += v[i];
            maxi = max(maxi, v[i]);
        }
        if (n <= 2)
        {
            cout << -1 << '\n';
            continue;
        }
        int lo = 0, hi = 1e12, ans = -1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            int cnt = 0, newSum = sum + mid;
            double avg = (double)newSum / (n * 2.0);
            for (int i = 0; i < n; i++)
            {
                if (v[i] < avg)
                    cnt++;
            }

            if (cnt > n / 2)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}