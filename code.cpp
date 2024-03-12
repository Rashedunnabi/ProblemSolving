#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define _test     \
    int _TEST;    \
    cin >> _TEST; \
    while (_TEST--)
#define ff first
#define ss second
#define pb push_back

int main()
{
    _test
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n), b(m), c(k);

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        for (int i = 0; i < k; i++)
            cin >> c[i];

        vector<array<int, 2>> d(n - 1);

        for (int i = 0; i < n - 1; i++)
        {
            d[i][0] = a[i + 1] - a[i];
            d[i][1] = i;
        }

        sort(d.rbegin(), d.rend());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int res1 = d[0][0], res2 = 0;
        int id = d[0][1];
        if (n > 2)
            res2 = d[1][0];

        int res = res1;
        for (int i = 0; i < m; i++)
        {
            int l = a[id], r = a[id + 1];
            int mid = ((ll)l + r) / 2;
            int t = lower_bound(c.begin(), c.end(), mid - b[i]) - c.begin();
            for (int j = max(0, t - 3); j <= min(k - 1, t + 3); j++)
            {
                if (b[i] + c[j] >= l && b[i] + c[j] <= r)
                    res = min(res, max(b[i] + c[j] - a[id], a[id + 1] - b[i] - c[j]));
            }
        }

        cout << max(res, res2) << '\n';
    }
}