#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 100000007;
int dp[55][1005];

int func(int j, int amount, vector<int> &coins, vector<int> &count)
{
    if (amount == 0)
        return 1;
    if (j < 0)
        return 0;
    if (dp[j][amount] != -1)
        return dp[j][amount];

    int ans = 0;
    for (int i = 0; i <= count[j]; i++)
    {
        if (amount - (i * coins[j]) >= 0)
            ans += func(j - 1, amount - (i * coins[j]), coins, count);

        ans %= MOD;
    }
    return dp[j][amount] = ans;
}

void solution()
{
    memset(dp, -1, sizeof(dp));

    int n, k, i;
    cin >> n >> k;
    vector<int> coins(n), count(n);
    for (int &i : coins)
        cin >> i;
    for (int &i : count)
        cin >> i;

    cout << func(n - 1, k, coins, count) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ": ";
        solution();
    }
    return 0;
}