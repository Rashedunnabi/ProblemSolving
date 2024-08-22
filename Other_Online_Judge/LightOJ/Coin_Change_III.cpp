#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solution()
{
    int n, m, ans = 0;
    cin >> n >> m;

    vector<int> coins(n), cnt(n);
    for (int &i : coins)
        cin >> i;
    for (int &i : cnt)
        cin >> i;

    int maxSize = accumulate(cnt.begin(), cnt.end(), 0); // Maximum possible size

    maxSize = max(m, maxSize);
    vector<int> dp(maxSize + 1, 0);
    dp[0] = 1;

    for (int j = 0; j < n; ++j)
    {
        int siz = cnt[j] * coins[j];
        for (int i = 0; i <= m && i <= maxSize && i < siz; i++)
        {
            dp[i + coins[j]] |= dp[i];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        ans += (dp[i] > 0);
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        solution();
    }
    return 0;
}
