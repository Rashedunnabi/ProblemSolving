#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define all(v) v.begin(), v.end()

void solution()
{
    ll n, m, k, i;
    cin >> n >> m >> k;

    ll arr[n];
    vector<pair<ll, ll>> vec, ans;

    for (ll i = 0; i < n; ++i)
    {
        cin >> arr[i];
        vec.push_back({arr[i], i});
    }
    sort(vec.begin(), vec.end());
    for (ll i = 0; i < n; ++i)
    {
        int x = 0;
        if (k >= m)
        {
            x = m;
            k -= m;
        }
        else
        {
            x = k;
            k = 0;
        }

        ans.push_back({vec[i].second, x});
    }

    sort(ans.begin(), ans.end());

    ll res = 0, taken = 0;

    for (ll i = 0; i < n; ++i)
    {
        ll x = ans[i].first;
        ll y = ans[i].second;
        res += ((arr[x] + taken) * y);
        taken += y;
    }

    cout << res << endl;
}

int main()
{
    Faster;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solution();
    }
    return 0;
}