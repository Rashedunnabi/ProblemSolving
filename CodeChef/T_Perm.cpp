#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int i, n;
        cin >> n;

        if (n % 3 == 0)
        {
            for (i = 1; i <= n; i += 3)
                cout << i << ' ' << i + 2 << ' ' << i + 1 << ' ';
            cout << '\n';
        }
        else if (n % 3 == 1)
        {
            for (i = 1; i + 3 <= n; i += 3)
                cout << i << ' ' << i + 2 << ' ' << i + 1 << ' ';
            cout << n << '\n';
        }
        else
        {
            cout << "4 5 2 1 3 ";
            for (i = 6; i <= n; i += 3)
                cout << i + 2 << ' ' << i + 1 << ' ' << i << ' ';
            cout << '\n';
        }
    }
    return 0;
}