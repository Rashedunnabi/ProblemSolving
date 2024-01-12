#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int dp[110][3000010];

int func(int ind, int amount, const vector<int> &coins)
{
    if (amount == 0)
        return 1;
    if (ind < 0)
        return 0;
    if (dp[ind][amount] != -1)
        return dp[ind][amount];

    int ways = 0;
    for (int used = 0; used * coins[ind] <= amount; used++)
    {
        ways = (ways + func(ind - 1, amount - used * coins[ind], coins)) % mod;
    }

    return dp[ind][amount] = ways;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int n, amount;
    cin >> n >> amount;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    int ans = func(n - 1, amount, coins);

    cout << ans << endl;

    return 0;
}
