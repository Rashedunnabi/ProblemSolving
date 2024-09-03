#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        b %= 2;

        bool flag = true;
        if (a & 1 || (b & 1 && a == 0))
            flag = false;

        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}