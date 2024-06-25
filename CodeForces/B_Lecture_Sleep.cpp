// In the name of ALLAH
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 7;
int ar[N], t[N], val[N];

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, k, i, sum = 0, ans = 0;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
        cin >> ar[i];
    for (i = 1; i <= n; i++)
        cin >> t[i];
    for (i = 1; i <= n; i++)
    {
        if (t[i])
            sum += ar[i];
        else
            val[i] = ar[i];
    }
    for (i = 1; i <= N; i++)
        val[i] += val[i - 1];
    for (i = 1; i <= n; i++)
    {
        int x = val[i + k - 1] - val[i - 1];
        ans = max(ans, sum + x);
    }
    cout << ans << '\n';
    return 0;
}