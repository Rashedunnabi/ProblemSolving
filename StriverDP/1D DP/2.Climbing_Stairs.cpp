#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dp[50];
    int func(int amount)
    {
        if (amount == 0)
            return 1;
        if (dp[amount] != -1)
            return dp[amount];

        int ans = 0;
        if (amount > 0)
            ans += func(amount - 1);
        if (amount > 1)
            ans += func(amount - 2);

        return dp[amount] = ans;
    }
    int climbStairs(int n) // with memoization
    {
        memset(dp, -1, sizeof(dp));
        return func(n);
    }

    // with tabulation
    int climbStairs2(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = (dp[i - 1] + 0LL + dp[i - 2]);
        return dp[n];
    }

    // with space optimization
    int climbStairs3(int n)
    {
        int pre2 = 0, pre = 1;
        for (int i = 2; i <= n + 1; i++)
        {
            int cur = pre2 + pre;
            pre2 = pre, pre = cur;
        }
        return pre;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.climbStairs(n) << '\n';
        cout << ob.climbStairs2(n) << '\n';
        cout << ob.climbStairs3(n) << '\n';
    }
    return 0;
}