#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"

const ll N = 1e5 + 7;
vector<ll> nums;
bool dp[N];

bool func(ll amount, vector<ll> &coins)
{
    if (amount == 1)
        return true;
    if (dp[amount] != false)
        return dp[amount];

    ll ans = false;
    for (auto coin : coins)
    {
        if (amount % coin == 0)
        {
            ans |= func(amount / coin, coins);
        }
    }
    return dp[amount] = ans;
}

bool isBinaryDecimal(ll num)
{
    while (num > 0)
    {
        ll digit = num % 10;
        if (digit != 0 && digit != 1)
            return false;
        num /= 10;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll t = 1;
    cin >> t;

    for (ll i = 2; i <= N; i++)
    {
        if (isBinaryDecimal(i))
            nums.push_back(i);
    }

    memset(dp, false, sizeof(dp));
    dp[1] = true;

    while (t--)
    {
        ll number, i;
        cin >> number;

        if (func(number, nums))
            yes;
        else
            no;
    }
    return 0;
}