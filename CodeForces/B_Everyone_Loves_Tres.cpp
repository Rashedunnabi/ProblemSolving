#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (n == 1 || n == 3)
        {
            cout << -1 << '\n';
            continue;
        }
        if (n == 2)
        {
            cout << "66\n";
            continue;
        }
        if (n == 4)
        {
            cout << "3366\n";
            continue;
        }
        for (int i = 0; i < n - 4; i++)
            cout << "3";
        cout << "6366\n";
    }
    return 0;
}