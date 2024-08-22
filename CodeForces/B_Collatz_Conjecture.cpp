#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define int long long

void solution()
{
    int x, y, k;
    cin >> x >> y >> k;

    while (k > 0)
    {
        int nxt = (1 + x / y) * y;
        int dif = nxt - x;
        if (dif > k)
        {
            cout << x + k << '\n';
            return;
        }
        k -= dif;

        while (nxt % y == 0)
            nxt /= y;

        x = nxt;

        if (x == 1)
        {
            x += k % (y - 1);
            break;
        }
    }

    cout << x << '\n';
}

int32_t main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}