#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int a, b, c, h = 0, ans = 0;
        cin >> a >> b >> c;
        if (a + 1 != c)
        {
            cout << -1 << '\n';
            continue;
        }
        while ((1 << h) <= a)
        {
            a -= (1 << h);
            h++;
        }

        if (!a && !b)
        {
            cout << h << '\n';
            continue;
        }

        if (a + b >= (1 << h))
        {
            b -= (1 << h);
            int k = (a + b + c - 1) / c;
            cout << h + k + 1 << '\n';
        }
        else
        {
            cout << h + 1 << '\n';
        }
    }
    return 0;
}