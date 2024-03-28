#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
const ll mod = 1e9 + 7;

long long power(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solution()
{
    ll n, k, i;
    cin >> n >> k;
    vector<ll> nums(n);
    for (ll &i : nums)
        cin >> i;

    ll maxSum = 0, sum = 0, s = 0;
    for (ll i = 0; i < n; i++)
    {
        sum = max(nums[i], sum + nums[i]);
        maxSum = max(maxSum, sum);
        s += nums[i];
    }

    ll ans = ((power(2, k, mod) % mod) - 1 + mod) % mod;
    ans = ((ans % mod) * 1LL * (maxSum % mod)) % mod;
    ans = (ans + 0LL + (s % mod) + mod) % mod;
    cout << ans << '\n';
}

int main()
{
    Faster;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}