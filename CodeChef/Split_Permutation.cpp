#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (n & 1)
        {
            for (int i = 1; 2 * i <= n; i++)
                cout << i << ' ' << n - i << ' ';
            cout << n << '\n';
        }
        else
        {
            for (int i = 1; 2 * i <= n; i++)
                cout << i << ' ' << 1 + n - i << ' ';
            cout << '\n';
        }
    }
    return 0;
}