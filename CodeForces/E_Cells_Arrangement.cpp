#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            if (i != 2)
                cout << i << ' ' << i << '\n';
        }
        cout << 2 << ' ' << 1 << '\n';
    }
    return 0;
}