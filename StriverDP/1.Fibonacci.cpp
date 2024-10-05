#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    long long func(int n, vector<long long> &dp)
    {
        if (n <= 1)
            return n;
        if (dp[n] != -1)
            return dp[n];
        return dp[n] = (func(n - 1, dp) + 0LL + func(n - 2, dp)) % mod;
    }
    long long int topDown(int n) // with recursion
    {
        vector<long long> dp(n + 1, -1);
        return func(n, dp);
    }
    long long int bottomUp(int n) // with tabulation
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = (dp[i - 1] + 0LL + dp[i - 2]) % mod;
        return dp[n];
    }

    long long int bottomUp2(int n) // with space optimization
    {
        // with space optimization
        int pre2 = 0, pre = 1;
        for (int i = 2; i <= n; i++)
        {
            int cur = (pre + 0LL + pre2) % mod;
            pre2 = pre;
            pre = cur;
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
        cout << ob.bottomUp(n) << '\n';
        cout << ob.topDown(n) << '\n';
    }
    return 0;
}