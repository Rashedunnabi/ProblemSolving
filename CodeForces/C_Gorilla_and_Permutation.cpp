#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = n; i >= 1; i--)
            cout << i << ' ';
        cout << '\n';
    }
    return 0;
}