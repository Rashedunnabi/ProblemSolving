#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll build_num(ll bit[])
{
    ll ans = 0;
    for (ll i = 0; i < 32; i++)
        if (bit[i])
            ans += (1 << i);

    return ans;
}
bool check(ll k, vector<ll> &arr)
{
    ll n = arr.size();

    ll bit[32] = {0};
    for (ll i = 0; i < k; i++)
    {
        for (ll j = 0; j < 32; j++)
        {
            if (arr[i] & (1 << j))
                bit[j]++;
        }
    }
    ll preOr = build_num(bit);
    for (ll i = k; i < n; i++)
    {
        for (ll j = 0; j < 32; j++)
        {
            if (arr[i - k] & (1 << j))
                bit[j]--;
        }
        for (ll j = 0; j < 32; j++)
        {
            if (arr[i] & (1 << j))
                bit[j]++;
        }
        ll newOr = build_num(bit);
        if (newOr != preOr)
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, i;
        cin >> n;
        vector<ll> v(n);
        for (ll &i : v)
            cin >> i;

        ll lo = 0, hi = n, mid;
        while (hi - lo > 1)
        {
            mid = lo + (hi - lo) / 2;
            if (check(mid, v))
                hi = mid;
            else
                lo = mid;
        }
        cout << hi << '\n';
    }
    return 0;
}