#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const ll mod = 1e9 + 7;
const ll N = 2e5 + 7;

void solution()
{
    ll n;
    cin >> n;
    vector<ll> nums(n);
    map<ll, int> mp;
    map<ll, bool> vis;

    for (ll j = 0; j < n; ++j)
    {
        cin >> nums[j];
        mp[nums[j]]++;
    }

    ll ans = 0;
    for (auto val : mp)
    {
        ll num = val.first;

        if (vis.find(num) != vis.end())
            continue;

        ll mask = num;
        for (ll i = 0; i < 31; ++i)
        {
            mask ^= (1LL << i);
        }

        if (mp.find(mask) == mp.end())
        {
            ans += val.second;
            continue;
        }
        vis[mask] = true;
        ans += max(val.second, mp[mask]);
    }
    cout << ans << "\n";
}

main()
{
    Faster;
    ll t;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}
