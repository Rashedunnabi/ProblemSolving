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
        int n, i;
        cin >> n;
        for (i = 0; i < n - 1; i++)
            cout << 3 << ' ';
        cout << 1 << '\n';
    }
    return 0;
}