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
        ll n, k, i;
        cin >> n >> k;
        vector<ll> v(n);
        for (auto &val : v)
            cin >> val;
        sort(v.begin(), v.end());

        for (i = 0; i < k; i++)
        {
            v[i] = max(v[i], 7 - v[i]);
        }
        ll sum = accumulate(v.begin(), v.end(), 0LL);

        cout << sum << '\n';
    }
    return 0;
}