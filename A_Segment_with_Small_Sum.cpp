#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll n, target;
    cin >> n >> target;
    vector<ll> v(n);
    for (ll &i : v)
        cin >> i;

    ll i, j, sum, ans;
    i = j = sum = ans = 0;

    while (i < n)
    {
        while (sum < target)
        {
            sum += v[j++];
            ans = max(ans, j - i);
        }
    }

    return 0;
}