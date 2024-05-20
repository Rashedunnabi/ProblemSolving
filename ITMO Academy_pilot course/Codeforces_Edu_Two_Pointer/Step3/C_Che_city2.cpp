#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    ll n, dis;
    cin >> n >> dis;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    ll ans = 0, i = 0;
    for (int j = 0; j < n; j++)
    {
        while (i < n && v[j] - v[i] > dis)
            i++;
        ans += i;
    }
    cout << ans << '\n';

    return 0;
}