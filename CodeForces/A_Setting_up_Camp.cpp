#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        int ans = a + (b / 3);
        b %= 3;
        if (b == 1)
        {
            c -= 2;
            ans++;
        }
        else if (b == 2)
        {
            c -= 1;
            ans++;
        }
        if (c < 0)
            cout << -1 << '\n';
        else
        {
            ans += (c + 2) / 3;
            cout << ans << '\n';
        }
    }
    return 0;
}