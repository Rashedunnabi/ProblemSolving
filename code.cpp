#include <bits/stdc++.h>
using namespace std;
void testCase()
{
    int x, y, k;
    cin >> x >> y >> k;
    while (k > 0)
    {
        int nxt = (1 + x / y) * y;
        if (nxt - x > k)
        {
            cout << x + k << "\n";
            return;
        }
        k -= nxt - x;
        while (nxt % y == 0)
        {
            nxt /= y;
        }
        x = nxt;
        if (x == 1)
        {
            break;
        }
    }
    if (k)
    {
        x += k % (y - 1);
    }
    cout << x << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--)
    {
        testCase();
    }
    return 0;
}