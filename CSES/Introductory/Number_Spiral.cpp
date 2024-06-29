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
        int a, b, ans;
        cin >> a >> b;

        if (b >= a)
        {
            if (b & 1)
                ans = b * b - a + 1;
            else
                ans = (b - 1) * (b - 1) + a;
        }
        else
        {
            if (a & 1)
                ans = (a - 1) * (a - 1) + b;
            else
                ans = a * a - b + 1;
        }
        cout << ans << endl;
    }
    return 0;
}