#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> pre(n + 3), suf(n + 3), v(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> v[i];

        for (int i = 1; i < n; i++)
        {
            ll a = v[i + 1] - v[i];
            ll b = v[i] - v[i - 1];
            if (i == 1 || a < b)
                pre[i] = 1;
            else
                pre[i] = a;
            pre[i] += pre[i - 1];
        }

        for (int i = n; i > 1; i--)
        {
            ll a = v[i + 1] - v[i];
            ll b = v[i] - v[i - 1];
            if (i == n || a > b)
                suf[i] = 1;
            else
                suf[i] = b;
            suf[i] += suf[i + 1];
        }

        // for (int i = 1; i <= n; i++)
        // {
        //     cout << pre[i] << ' ';
        // }
        // cout << '\n';
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << suf[i] << ' ';
        // }
        // cout << '\n';

        int m;
        cin >> m;
        while (m--)
        {
            int x, y;
            cin >> x >> y;
            if (x < y)
            {
                cout << pre[y - 1] - pre[x - 1] << "\n";
            }
            else
            {
                cout << suf[y + 1] - suf[x + 1] << "\n";
            }
        }
    }
    return 0;
}
