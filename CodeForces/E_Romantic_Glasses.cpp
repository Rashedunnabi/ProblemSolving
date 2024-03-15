#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"

bool check(vector<ll> &arr, ll k)
{
    ll n = arr.size();
    ll prefix[n];
    prefix[0] = arr[0];
    for (ll i = 1; i < n; i++)
    {
        prefix[i] = arr[i] + prefix[i - 1];
    }
    unordered_map<ll, ll> mp;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {

        if (prefix[i] == k || mp.find(prefix[i] - k) != mp.end())
        {
            return true;
        }

        mp[prefix[i]]++;
    }

    return false;
}

void solution()
{
    ll n, i;
    cin >> n;

    vector<ll> arr(n);
    for (i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (i & 1)
            arr[i] = -x;
        else
            arr[i] = x;
    }

    if (check(arr, 0))
        yes;
    else
        no;
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