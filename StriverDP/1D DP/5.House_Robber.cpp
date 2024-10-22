#include <bits/stdc++.h>
using namespace std;

int func(int i, vector<int> &arr, vector<int> &dp)
{
    if (i == 0)
        return arr[0];
    if (i < 0)
        return 0;

    if (dp[i] != -1)
        return dp[i];

    int take = arr[i] + func(i - 2, arr, dp);
    int notTake = func(i - 1, arr, dp);

    return dp[i] = max(take, notTake);
}

int houseRobber(vector<int> &arr) // with recursion and memoization
{
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    return func(n - 1, arr, dp);
}

int houseRobber2(vector<int> &arr) // with tabulation
{
    int n = arr.size();
    vector<int> dp(n);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int take = arr[i] + (i > 1 ? dp[i - 2] : 0);
        int notTake = dp[i - 1];
        dp[i] = max(take, notTake);
    }
    return dp[n - 1];
}

int houseRobber3(vector<int> &arr) // with space optimization
{
    int n = arr.size(), pre2 = 0, pre = arr[0];
    for (int i = 1; i < n; i++)
    {
        int take = arr[i] + (i > 1 ? pre2 : 0);
        int notTake = pre;
        int cur = max(take, notTake);
        pre2 = pre, pre = cur;
    }
    return pre;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << houseRobber2(arr) << '\n';

    return 0;
}