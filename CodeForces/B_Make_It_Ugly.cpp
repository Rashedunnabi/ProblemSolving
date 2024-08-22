#include <bits/stdc++.h>
using namespace std;
int main()
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
        int mini = *min_element(v.begin(), v.end()), maxi = *max_element(v.begin(), v.end());
        if (mini == maxi)
        {
            cout << -1 << '\n';
            continue;
        }

        int ans = n - 1, cnt = 0;
        for (i = 0; i < n; i++)
        {
            if (v[i] == v[0])
            {
                cnt++;
            }
            else
            {
                ans = min(ans, cnt);
                cnt = 0;
            }
        }
        if (cnt)
            ans = min(ans, cnt);
        cout << ans << '\n';
    }
    return 0;
}