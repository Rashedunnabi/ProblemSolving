// In the name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 7;
int ar[N], op[N], l[N], r[N], val[N], v[N];

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int i, n, m, k;
    cin >> n >> m >> k;

    for (i = 1; i <= n; i++)
        cin >> ar[i];

    for (i = 1; i <= m; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        l[i] = a, r[i] = b, val[i] = x;
    }

    for (i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        op[x]++, op[y + 1]--;
    }

    for (i = 1; i <= m; i++)
        op[i] += op[i - 1];

    for (i = 1; i <= m; i++)
    {
        v[l[i]] += (op[i] * val[i]);
        v[r[i] + 1] -= (op[i] * val[i]);
    }

    for (i = 1; i <= n; i++)
        v[i] += v[i - 1];

    for (i = 1; i <= n; i++)
        cout << v[i] + ar[i] << ' ';
    cout << '\n';

    return 0;
}