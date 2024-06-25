#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, i;
        cin >> n >> m;

        vector<ll> arr(n + 4);

        for (i = 0; i < m; i++)
        {
            ll a, b, k;
            cin >> a >> b >> k;

            arr[a] += k;
            arr[b + 1] -= k;
        }
        for (i = 1; i <= n; i++)
            arr[i] = arr[i] + arr[i - 1];

        int q;
        cin >> q;
        while (q--)
        {
            int x;
            cin >> x;
            cout << arr[x] << '\n';
        }
    }
    return 0;
}
