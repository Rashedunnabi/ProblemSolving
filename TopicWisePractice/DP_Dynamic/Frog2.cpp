#include <bits/stdc++.h>
using namespace std;
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int N = 1e5 + 7;
int h[N], dp[N];

int func(int i, int k)
{
    if (i <= 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int ans = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        ans = min(ans, func(i - j, k) + abs(h[i] - h[i - j]));
    }

    return dp[i] = ans;
}

int main()
{
    Faster;
    int n, i, k;
    cin >> n >> k;

    memset(dp, -1, sizeof(dp));
    for (i = 0; i < n; i++)
        cin >> h[i];

    cout << func(n - 1, k) << '\n';

    return 0;
}