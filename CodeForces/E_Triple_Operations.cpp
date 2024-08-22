#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 10;
int dp[N];

int func(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum++;
        n /= 3;
    }
    return sum;
}

int32_t main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    for (int i = 1; i < N; i++)
        dp[i] = dp[i - 1] + func(i);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int l, r, ans = 0;
        cin >> l >> r;

        ans = 2 * func(l);
        ans += dp[r] - dp[l];
        cout << ans << '\n';
    }
    return 0;
}