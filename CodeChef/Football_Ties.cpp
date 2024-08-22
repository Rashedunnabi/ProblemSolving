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
        int x, y;
        cin >> x >> y;
        int ans = 0;
        ans = max(x % 3, y % 3);
        cout << ans << '\n';
    }
    return 0;
}