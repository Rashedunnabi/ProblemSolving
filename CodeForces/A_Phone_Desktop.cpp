#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        int ans = max((y + 1) / 2, (4 * y + x + 14) / 15);
        cout << ans << '\n';
    }
    return 0;
}