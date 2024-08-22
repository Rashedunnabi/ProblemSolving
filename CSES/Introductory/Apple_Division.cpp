#include <bits/stdc++.h>
using namespace std;
#define Rashed ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

int main()
{
    Rashed;
    int n, i;
    cin >> n;
    int sz = 1 << n;
    ll ans = 1e18 + 7;

    ll arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    for (int mask = 0; mask < sz; mask++)
    {
        ll s = 0, ss = 0;

        for (i = 0; i < n; i++)
        {
            if ((mask >> i) & 1 != 0)
                ss += arr[i];
            else
                s += arr[i];
        }
        ans = min(ans, abs(s - ss));
    }
    cout << ans << endl;
    return 0;
}
