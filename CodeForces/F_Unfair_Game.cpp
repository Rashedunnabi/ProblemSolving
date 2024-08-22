#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int a, b, c, d, ans;
        cin >> a >> b >> c >> d;
        ans = (a / 2) + (b / 2) + (c / 2) + (d / 2);
        if (a & 1 && b & 1 && c & 1)
            ans++;
        cout << ans << '\n';
    }
    return 0;
}