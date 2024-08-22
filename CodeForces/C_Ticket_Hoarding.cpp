#include <bits/stdc++.h>
using namespace std;

#define Faster ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define all(v) v.begin(), v.end()

void solution()
{
    int n, m, k, i;
    cin >> n >> m >> k;
    vector<pair<int, int>> vp;
    vector<int> v(n), arr(n);
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        vp.push_back({arr[i], i});
    }
    sort(all(vp));

    for (i = 0; i < n; i++)
    {
        int x = min(m, k);
        k -= x;
        int ind = vp[i].second;
        v[ind] = x;
    }

    ll ans = 0, take = 0;

    for (i = 0; i < n; i++)
    {
        ans += (v[i] * 1LL * (arr[i] + 0LL + take));
        take += v[i];
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