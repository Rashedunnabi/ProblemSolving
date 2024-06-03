#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int i, n, m, S, A, B, ans = 0;
    cin >> n >> m >> S >> A >> B;

    vector<int> va(n), vb(m);
    for (int &i : va)
        cin >> i;
    for (int &i : vb)
        cin >> i;

    sort(va.rbegin(), va.rend());
    sort(vb.rbegin(), vb.rend());

    int r = min(S / A, n) - 1, sum = (r + 1) * A, cost = 0;

    for (i = 0; i <= r; i++)
        cost += va[i];

    ans = cost;
    for (i = 0; i < min(m, S / B); i++)
    {
        sum += B;
        cost += vb[i];
        while (sum > S)
        {
            sum -= A;
            cost -= va[r--];
        }
        ans = max(ans, cost);
    }
    cout << ans << '\n';
    return 0;
}