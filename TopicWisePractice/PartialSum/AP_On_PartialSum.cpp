#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q, i;
    cin >> n >> q;

    vector<int> v(n + 2), ar(n + 2), br(n + 2);
    while (q--)
    {
        int a, d, l, r;
        cin >> a >> d >> l >> r;

        ar[l] += (a - (l * d));
        ar[r + 1] -= (a - (l * d));
        br[l] += d;
        br[r + 1] -= d;
    }

    for (i = 1; i <= n; i++)
    {
        ar[i] += ar[i - 1];
        br[i] += br[i - 1];
    }

    for (i = 1; i <= n; i++)
        v[i] = ar[i] + (i * br[i]);

    for (i = 1; i <= n; i++)
        cout << v[i] << ' ';
    cout << '\n';

    return 0;
}