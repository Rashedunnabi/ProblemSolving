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

    ll i, j = 0, sum = 0, ans = n + 1;
    for (i = 0; i < n; i++)
    {
        sum += v[i];
        while (sum - v[j] >= target)
            sum -= v[j++];

        if (sum >= target)
            ans = min(ans, i - j + 1);
    }
    cout << (ans == n + 1 ? -1 : ans) << '\n';
    return 0;
}