#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2 == 0)
        {
            cout << -1 << '\n';
        }
        else
        {
            int mid = n / 2;
            for (int i = 1; i <= mid; i++)
                cout << i << ' ';
            for (int i = n; i > mid; i--)
                cout << i << ' ';
            cout << '\n';
        }
    }
    return 0;
}