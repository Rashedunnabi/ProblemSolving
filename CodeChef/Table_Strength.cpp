#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

const int mod = 1e9 + 7;
const int N = 2e5 + 7;

void solution()
{
    int n, i;
    cin >> n;
    vector<ll> v(n);
    for (auto &e : v)
        cin >> e;
    sort(rall(v));
    ll ans = v[0], mini = INT_MAX;
    for (i = 0; i < n; i++)
    {
        mini = min(mini, v[i]);
        ll val = mini * 1ll * (i + 1);
        ans = max(ans, val);
    }
    cout << ans << '\n';
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