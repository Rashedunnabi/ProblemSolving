#include <bits/stdc++.h>
using namespace std;
#define int long long

/*#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mx = 4e4 + 10, mod = 1e9 + 7;
int dp[500][mx];
vector<int> palindrome;

int func(int idx, int sum)
{
    if (sum == 0)
        return 1;
    if (sum < 0 || idx >= palindrome.size())
        return 0;

    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    int notTake = func(idx + 1, sum);
    int take = func(idx, sum - palindrome[idx]);

    return dp[idx][sum] = (notTake + take) % mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    for (int i = 1; i < mx; i++)
    {
        string s = to_string(i);
        if (string(s.rbegin(), s.rend()) == s)
            palindrome.push_back(i);
    }
    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while (t--)
    {
        int n;
        cin >> n;
        cout << func(0, n) << '\n';
    }
    return 0;
}*/

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int mx = 4e4 + 10, mod = 1e9 + 7;
    vector<int> palindrome, dp(mx);
    for (int i = 1; i < mx; i++)
    {
        string s = to_string(i);
        if (string(s.rbegin(), s.rend()) == s)
            palindrome.push_back(i);
    }

    dp[0] = 1;
    for (int x : palindrome)
    {
        for (int i = x; i < mx; i++)
            dp[i] = (dp[i] + dp[i - x]) % mod;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}