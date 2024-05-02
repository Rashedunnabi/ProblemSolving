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
        ll a, b;
        cin >> a >> b;
        ll ans = a;
        for (ll i = 2; i <= b; i++)
            ans += (a + i) / (i * i);
        cout << ans << endl;
    }
    return 0;
}