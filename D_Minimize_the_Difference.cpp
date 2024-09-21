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
        int ans = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
        int x = 100;
        while (x--)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (v[i] > v[i + 1])
                {
                    int x = v[i] + v[i + 1];
                    int mid = x / 2;
                    v[i] = mid;
                    v[i + 1] = x - mid;
                }
            }
            int ans2 = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
            ans = min(ans, ans2);

            for (int i = n - 2; i > 0; i--)
            {
                if (v[i] > v[i + 1])
                {
                    int x = v[i] + v[i + 1];
                    int mid = x / 2;
                    v[i] = mid;
                    v[i + 1] = x - mid;
                }
            }
            ans2 = *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
            ans = min(ans, ans2);
        }
        cout << ans << '\n';
    }
    return 0;
}