#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll l, r, dif;
        cin >> l >> r;
        ll ans = __lg(r);
        cout << ans << '\n';
    }
    return 0;
}