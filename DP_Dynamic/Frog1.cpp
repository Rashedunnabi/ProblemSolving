#include <bits/stdc++.h>
using namespace std;
#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

const int N = 1e5 + 7;
int h[N], dp[N];

int func(int i)
{
    if (i <= 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int ans = INT_MAX;
    // way 1....jump backword from 1 piller
    ans = min(ans, func(i - 1) + abs(h[i] - h[i - 1]));
    // way 2....jump backword from 2 piller
    ans = min(ans, func(i - 2) + abs(h[i] - h[i - 2]));

    return dp[i] = ans;
}

int main()
{
    Faster;
    int n, i;
    cin >> n;

    memset(dp, -1, sizeof(dp));
    for (i = 0; i < n; i++)
        cin >> h[i];

    cout << func(n - 1) << '\n';

    return 0;
}