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
        int n, q, maxi = -1;
        cin >> n >> q;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            maxi = max(maxi, x);
        }
        while (q--)
        {
            char ch;
            int l, r;
            cin >> ch >> l >> r;
            if (maxi <= r && maxi >= l)
            {
                if (ch == '+')
                    maxi++;
                else
                    maxi--;
            }
            cout << maxi << ' ';
        }
        cout << '\n';
    }
    return 0;
}