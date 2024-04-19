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
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n);
        for (auto &e : v)
            cin >> e;
        ll i = 0, j = n - 1, left = (k + 1) / 2, right = k / 2;

        while (i < n && left >= v[i])
            left -= v[i++];
        if (i < n)
            v[i] -= left;

        while (j >= i && right >= v[j])
            right -= v[j--];

        if (j >= i)
            cout << n - (j - i + 1) << '\n';
        else
            cout << n << '\n';
    }
    return 0;
}