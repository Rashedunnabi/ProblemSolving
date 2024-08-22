#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;

        map<ll, ll> freq;
        ll ans = 0;

        for (ll i = n - 1; i >= 0; i--)
        {
            ll cur = a[i];
            if (freq.count(cur))
                ans += freq[cur];
            if (cur == 1 || (3 * cur) % (cur - 1))
                continue;
            ll reqAi = (3 * cur) / (cur - 1);
            freq[reqAi]++;
        }
        cout << ans << '\n';
    }
    return 0;
}