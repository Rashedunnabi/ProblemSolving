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
        ll n, i;
        cin >> n;
        ll ar[n];
        for (i = 0; i < n; i++)
            cin >> ar[i];
        sort(ar, ar + n);
        ll ans = 0;
        for (i = 0; i < n; i++)
        {
            ans += abs(ar[i] - i);
        }
        cout << ans << '\n';
    }
    return 0;
}