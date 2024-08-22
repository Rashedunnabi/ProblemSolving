#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
const int inf = 1e9 + 20;
const int N = 100 + 10;
int dp[N];
int vals[] = {1, 3, 6, 10, 15};

int main()
{
    Faster;
    int t;
    cin >> t;

    for (int i = 1; i < N; i++)
    {
        dp[i] = inf;

        for (int j = 0; j < 5; j++)
        {
            if (vals[j] <= i)
                dp[i] = min(dp[i], dp[i - vals[j]] + 1);
        }
    }

    while (t--)
    {
        int n;
        cin >> n;

        int need = (n - 70) / 15;

        if (need < 0)
            need = 0;

        int ans = need;

        n -= need * 15;

        ans += dp[n];

        cout << ans << '\n';
    }
    return 0;
}
