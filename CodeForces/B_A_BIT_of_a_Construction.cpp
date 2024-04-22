#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, i;
        cin >> n >> k;

        if (n == 1)
        {
            cout << k << '\n';
            continue;
        }
        vector<ll> v;
        ll lg = log2(k);
        ll x = 1ll << lg;
        x -= 1;
        v.push_back(x);
        k -= x;
        v.push_back(k);
        for (i = 0; i < n - 2; i++)
            v.push_back(0);

        for (auto val : v)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}
