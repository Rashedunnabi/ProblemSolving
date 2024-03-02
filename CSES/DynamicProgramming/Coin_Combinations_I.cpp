#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<int> coins;
int dp[3000010];
const int mod = 1e9 + 7;

int func(int amount)
{
    if (amount == 0)
        return 1;

    if (dp[amount] != -1)
        return dp[amount];

    int ans = 0;

    for (int coin : coins)
    {
        if (amount - coin >= 0)
            ans = (ans + 0LL + func(amount - coin)) % mod;
    }
    return dp[amount] = ans % mod;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int n, i, amount;
    cin >> n >> amount;

    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        coins.push_back(x);
    }
    int ans = func(amount);

    cout << ans;

    return 0;
}
