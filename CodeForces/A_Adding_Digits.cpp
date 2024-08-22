#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int a, b, n;
    cin >> a >> b >> n;

    bool flag = true;
    for (int i = 0; i <= 9; i++)
    {
        if ((a * 10 + i) % b == 0)
        {
            flag = false;
            cout << a << i;
            for (int i = 0; i < n - 1; i++)
                cout << 0;
            cout << '\n';
            break;
        }
    }
    if (flag)
        cout << -1 << '\n';

    return 0;
}