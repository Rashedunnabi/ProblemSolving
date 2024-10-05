#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int func(int i, vector<int> &h, vector<int> &dp)
    {
        if (i == 0)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int cost = func(i - 1, h, dp) + abs(h[i] - h[i - 1]);
        if (i > 1)
            cost = min(cost, func(i - 2, h, dp) + abs(h[i] - h[i - 2]));
        return dp[i] = cost;
    }
    int frogJump(int n, vector<int> &heights) // with recursion and memoization
    {
        vector<int> dp(n + 1, -1);
        return func(n - 1, heights, dp);
    }

    // with tabulation
    int frogJump2(int n, vector<int> &h)
    {
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
            if (i > 1)
                dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
        }
        return dp[n - 1];
    }

    // with space optimization
    int frogJump3(int n, vector<int> &h)
    {
        int pre = 0, pre2 = 0;
        for (int i = 1; i < n; i++)
        {
            int cur = pre + abs(h[i] - h[i - 1]);
            if (i > 1)
                cur = min(cur, pre2 + abs(h[i] - h[i - 2]));
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.frogJump(n, arr) << '\n';
        cout << ob.frogJump2(n, arr) << '\n';
        cout << ob.frogJump3(n, arr) << '\n';
    }
    return 0;
}