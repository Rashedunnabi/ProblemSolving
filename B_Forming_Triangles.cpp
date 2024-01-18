#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long

void solution()
{
    ll n, i;
    cin >> n;

    ll arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    vector<ll> v;
    map<ll, ll> mp;

    for (i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto val : mp)
    {
        v.push_back(val.first);
    }

    ll ans = 0;
    n = v.size();
    vector<ll> pre(n);

    for (i = 0; i < n; i++)
    {
        ll x = mp[v[i]];
        if (x > 1)
        {
            pre[i] = x;
        }
        else
        {
            pre[i] = 1;
        }
    }

    for (i = 1; i < n; i++)
        pre[i] += pre[i - 1];
    for (i = 0; i < n; i++)
    {
        ll x = mp[v[i]];
        if (x == 1)
            continue;

        if (x >= 3)
        {
            ans += (x * 1LL * (x - 1) * (x - 2) / 6);
            if (i > 0)
                ans += (pre[i - 1] * (x * (x - 1) / 2));
        }
        else
        {
            if (i > 0)
                ans += (pre[i - 1] * (x * (x - 1) / 2));
        }
    }

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